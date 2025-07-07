import java.util.Scanner;

public class SimpleCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // 整数
        System.out.print("输入第一个整数: ");
        int num1 = scanner.nextInt();
        System.out.print("输入第二个整数: ");
        int num2 = scanner.nextInt();
        
        // 运算符
        System.out.print("输入运算符 (+, -, *, /): ");
        char operator = scanner.next().charAt(0);
        if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
            System.out.println("错误：无效的运算符！");
            return;
        }
        
        // 输出
        switch (operator) {
            case '+':
                System.out.println("结果: " + (num1 + num2));
                break;
            case '-':
                System.out.println("结果: " + (num1 - num2));
                break;
            case '*':
                System.out.println("结果: " + (num1 * num2));
                break;
            case '/':
                if (num2 == 0) {
                    System.out.println("错误：除数不能为零！");
                } else {
                    double result = (double) num1 / num2;
                    System.out.println("结果: " + result);
                }
                break;
        }
    }
}