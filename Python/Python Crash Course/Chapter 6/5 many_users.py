users ={
    "aeinstein": {
        "first": "albert",
        "last": "einstein",
        "location": "princeton",
    }
    "mcurie": {
        "first": "marie",
        "last": "curie",
        "location": "paris",
    }
}

for username, user_info in users.items():
    print(f"\nusername:{username}")
    print(f"\tfull name: {user_info['first']} {user_info['last']}")
    print(f"\tlocation: {user_info['location']}")