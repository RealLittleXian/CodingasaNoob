import java.util.Scanner;

class BMICalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("身高（m）：");
        double height = scanner.nextDouble();

        System.out.print("体重（kg）：");
        double weight = scanner.nextDouble();

        double bmi = weight / (height * height);

        System.out.printf("BMI = %.2f%n", bmi);
        
        scanner.close();
    }
}