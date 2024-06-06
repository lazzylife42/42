from rest_framework import serializers
from . models import BlogPost

class BlogPostSerialiser(serializers.ModelSerializer):
    class Meta:
        model = BlogPost
        fields = ["id", "title", "content", "published_date"]