favorite_languages = {
    "jen": "python",
    "sarah": "c",
    "edward": "ruby",
    "phil": "python",
}

language = favorite_languages["sarah"].title()
print("Sarah's favorite language is " + language + ".")

print('The following languages have been mentioned:')   # set 集合
for language in set(favorite_languages.values()):
    print(language.title())