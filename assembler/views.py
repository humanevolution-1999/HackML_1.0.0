from django.shortcuts import render
from .models import MyModel
from django.contrib.auth.models import User
from django.contrib.auth import authenticate, logout, login as auth_login
from datetime import datetime
from django.shortcuts import get_object_or_404, render
from django.http import HttpResponse, HttpResponseRedirect
from django.urls import reverse
from django.contrib import messages


#custom interpreter module output
from .interpreter import intepret

# Create your views here.


def index(request):
    if request.user.is_authenticated:
        user_name=request.user.username
        return HttpResponseRedirect(reverse("assembler:user_homepage",args=(user_name,))) 
    return render(request,"assembler/index.html")

def signup(request):
    if request.user.is_authenticated:
        user_name=request.user.username
        return HttpResponseRedirect(reverse("assembler:user_homepage",args=(user_name,))) 
    return render(request, "assembler/signup.html")

def about(request):
    return render(request,"assembler/about.html")

def signup_request(request):
    #print(request.POST["name"])
    if request.POST["password"]!=request.POST["confirm_password"]:
        messages.error(request, "Passwords do not match, try again!")
        return HttpResponseRedirect('signup') 
    try:
        selected_username = User.objects.get(username=request.POST["name"])
        messages.error(request, "Username already exists, try again!")
        return HttpResponseRedirect('signup')
    except(KeyError,User.DoesNotExist):
        #print("no user name exists")
        user = User.objects.create_user(request.POST["name"], request.POST["email"], request.POST["password"])
        user.save()
        user = authenticate(username=request.POST["name"], password=request.POST["password"])
        auth_login(request, user)

        #create session variables on successful login
        request.session['assembler_input']=""
        request.session['assembler_output']=""
        return HttpResponseRedirect(reverse("assembler:user_homepage",args=(request.POST["name"],)))

def user_homepage(request,user_name):
    user = get_object_or_404(User,username=user_name)
    if request.user.is_authenticated:
        return render(request,"assembler/user_homepage.html",{"user":user, "input_file":request.session['assembler_input'] ,"output_file":request.session['assembler_output']})
    else:
        return HttpResponseRedirect('../')

def ml_interpreter(request,user_name):
    user = get_object_or_404(User,username=user_name)
    if request.user.is_authenticated:
        request.session['assembler_input']=request.POST["input_file"]
        request.session['assembler_output']= intepret(request.session['assembler_input'])
        return HttpResponseRedirect(reverse("assembler:user_homepage",args=(user_name,))) 
    else:
        return HttpResponseRedirect('../')


def user_logout(request,user_name):
    logout(request)
    return HttpResponseRedirect("../")

def login(request):
    if request.user.is_authenticated:
        user_name=request.user.username
        return HttpResponseRedirect(reverse("assembler:user_homepage",args=(user_name,))) 
    else:
        return render(request,"assembler/login.html")

def login_request(request):
    user = authenticate(username=request.POST["name"], password=request.POST["password"])
    if user is not None:
        auth_login(request,user)
        request.session['assembler_input']=""
        request.session['assembler_output']=""
        return HttpResponseRedirect(reverse("assembler:user_homepage",args=(request.POST["name"],)))
    else:
        messages.error(request, "Invalid credentials, please try again!")
        return HttpResponseRedirect('login')





