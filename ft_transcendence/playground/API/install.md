## Install Python dependencies

**Creating a virtual environment**
```bash
python3 -m venv venv
```
**Launching the environment**
```bash
source venv/bin/activate
```
**Install requirements**
```bash
pip3 install -r requirements.txt
```

## Initialize Django

**Start a new project**
```bash
django-admin startproject mysite
```
**Create a new app**
```bash
cd mysite
python3 manage.py startapp api
```
**Connect the app**
in ```mysite/settings.py``` add your app and the ```rest_framework``` in ```INSTALLED_APPS``` list like this :
```bash
...
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    "api",
    "rest_framework",
]
...
```
**DB Migration**
```bash
python manage.py migrate
```
**Run Server**
```bash
python manage.py runserver
```