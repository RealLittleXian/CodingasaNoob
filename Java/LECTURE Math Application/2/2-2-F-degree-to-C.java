import java.util.Scanner;

class FahrenheitToCelsius {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("华氏温度（°F）：");
        double fahrenheit = scanner.nextDouble();

        double celsius = (fahrenheit - 32) * 5 / 9;

        System.out.printf("对应的摄氏温度（°C）：%.2f%n", celsius);
        
        scanner.close();
    }
}