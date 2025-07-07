
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

class Product {

    protected String name;
    protected double price;
    protected String description;

    public Product(String name, double price, String description) {
        this.name = name;
        this.price = price;
        this.description = description;
    }

    public void displayInfo() {
        System.out.println("--------------------");
        System.out.println("产品名称: " + this.name);
        System.out.println("产品价格: " + String.format("%.2f", this.price) + " 元");
        System.out.println("产品描述: " + this.description);
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public String getDescription() {
        return description;
    }
}

class Phone extends Product {

    public Phone(String name, double price, String description) {
        super(name, price, description);
    }

    public void makeCall() {
        System.out.println("使用 [" + this.name + "] 拨打电话...");
    }
}

class Tablet extends Product {

    public Tablet(String name, double price, String description) {
        super(name, price, description);
    }

    public void useTouchscreen() {
        System.out.println("操作 [" + this.name + "] 的触摸屏...");
    }
}

class Laptop extends Product {

    private int batteryCapacity;

    public Laptop(String name, double price, String description, int batteryCapacity) {
        super(name, price, description);
        this.batteryCapacity = batteryCapacity;
    }

    @Override
    public void displayInfo() {

        super.displayInfo();

        System.out.println("电池容量: " + this.batteryCapacity + "mAh");
    }

    public int getBatteryCapacity() {
        return batteryCapacity;
    }
}

public class SalesSystem {

    public static void main(String[] args) {

        List<Product> productList = new ArrayList<>();
        productList.add(new Phone("Phone Example 1", 100.00, "这是一个手机示例。"));
        productList.add(new Tablet("Tablet Example 1", 200.00, "这是一个平板示例。"));
        productList.add(new Laptop("Laptop Example 1", 300.00, "这是一个笔记本示例。", 5000));

        Scanner scanner = new Scanner(System.in);

        while (true) {
            printMenu();
            try {
                int choice = scanner.nextInt();
                scanner.nextLine();
                switch (choice) {
                    case 1:
                        createProduct(scanner, productList);
                        break;
                    case 2:
                        viewProducts(scanner, productList);
                        break;
                    case 3:
                        System.out.println("退出。");
                        scanner.close();
                        return;
                    default:
                        System.out.println("输入错误，请输入1、2或3。");
                }
            } catch (InputMismatchException e) {
                System.out.println("输入错误，请输入数字。");
                scanner.nextLine();
            }
            System.out.println("\n按 Enter键 继续。");
            scanner.nextLine();
        }
    }

    public static void printMenu() {
        System.out.println("\n=== 电子产品销售查看系统 ===");
        System.out.println("1. 创建新产品");
        System.out.println("2. 查看产品信息");
        System.out.println("3. 退出系统");
        System.out.print("请输入 (1-3): ");
    }

    private static void createProduct(Scanner scanner, List<Product> productList) {
        System.out.println("\n--- 创建新产品 ---");
        System.out.println("请选择要创建的产品类型:");
        System.out.println("1. 手机 (Phone)");
        System.out.println("2. 平板 (Tablet)");
        System.out.println("3. 笔记本电脑 (Laptop)");
        System.out.print("请输入类型编号: ");

        int type = scanner.nextInt();
        scanner.nextLine();

        System.out.print("请输入产品名称: ");
        String name = scanner.nextLine();
        System.out.print("请输入产品价格: ");
        double price = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("请输入产品描述: ");
        String description = scanner.nextLine();

        Product newProduct = null;
        switch (type) {
            case 1:
                newProduct = new Phone(name, price, description);
                break;
            case 2:
                newProduct = new Tablet(name, price, description);
                break;
            case 3:
                System.out.print("请输入笔记本电池容量 (mAh): ");
                int capacity = scanner.nextInt();
                scanner.nextLine(); // 消费换行符
                newProduct = new Laptop(name, price, description, capacity);
                break;
            default:
                System.out.println("无效的产品类型！创建失败。");
                return;
        }

        productList.add(newProduct);
        System.out.println("\n产品 [" + name + "] 创建成功！");
    }

    private static void viewProducts(Scanner scanner, List<Product> productList) {
        System.out.println("\n--- 查看产品信息 ---");
        if (productList.isEmpty()) {
            System.out.println("当前没有任何产品库存。请先创建产品。");
            return;
        }

        System.out.println("当前产品列表:");
        for (int i = 0; i < productList.size(); i++) {
            System.out.println((i + 1) + ". " + productList.get(i).getName());
        }

        System.out.print("\n请输入要查看产品的编号: ");
        int index = scanner.nextInt();
        scanner.nextLine(); // 消费换行符

        if (index > 0 && index <= productList.size()) {
            Product selectedProduct = productList.get(index - 1);

            System.out.println("\n--- 产品详细信息 ---");

            selectedProduct.displayInfo();

            if (selectedProduct instanceof Phone) {
                ((Phone) selectedProduct).makeCall();
            } else if (selectedProduct instanceof Tablet) {
                ((Tablet) selectedProduct).useTouchscreen();
            }
            System.out.println("--------------------");

        } else {
            System.out.println("无效的编号。");
        }
    }
}
