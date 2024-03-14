def make_pizza(size, *toppings):
    """Print the list of toppings that have been requested."""
    print(f"\nMaking a {size}-inch pizza with the following toppings:")
    for toppings in toppings:
        print(f" - {toppings}")

make_pizza(16,'pepperoni')
make_pizza(12,'mushrooms', 'green peppers', 'extra cheese')