from django.db import models
from django.contrib.auth.models import User

# Create your models here.

def user_directory_path(instance, filename):
    # file will be uploaded to MEDIA_ROOT/user_<id>/<filename>
    return "user_{0}/{1}".format(instance.user.username, filename)


class MyModel(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    uploaded_hack_l_file = models.FileField(upload_to=user_directory_path)
    upload_date = models.DateTimeField("Upload Date and Time")

    def __str__(self):
        return f"{self.user.username} - {self.uploaded_hack_l_file.name}"



    

