def greet_user(username):
    """Show simple greeting words."""
    print(f"\nHello, {username.title()}!")


name = input("What's your name please? ")
greet_user(name)
