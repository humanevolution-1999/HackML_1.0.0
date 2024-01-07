from django.urls import path
from django.conf.urls.static import static
from django.conf import settings

from . import views

app_name="assembler"
urlpatterns = [
    path("", views.index, name="index"),
    path("signup",views.signup,name="signup"),
    path("signup_request",views.signup_request,name="signup_request"),
    path("login",views.login,name="login"),
    path("about",views.about,name="about"),
    path("login_request",views.login_request,name="login_request"),
    path("<str:user_name>/user_homepage", views.user_homepage, name = "user_homepage"),
    path("<str:user_name>/ml_interpreter",views.ml_interpreter,name="ml_interpreter"),
    path("<str:user_name>/user_logout",views.user_logout, name="logout")
] #+ static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)

