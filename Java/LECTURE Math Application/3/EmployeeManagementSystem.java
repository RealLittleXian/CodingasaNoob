import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.InputMismatchException;

public class EmployeeManagementSystem {
    // 雇员类
    static class Employee {
        int id;
        String name;
        String position;
        int leaveDays;
        double basicSalary;
        
        public Employee(int id, String name, String position, int leaveDays, double basicSalary) {
            this.id = id;
            this.name = name;
            this.position = position;
            this.leaveDays = leaveDays;
            this.basicSalary = basicSalary;
        }
    }

    // 主程序
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Employee> employees = new ArrayList<>();
        int nextId = 1; // 下一个可用的雇员ID
        int option = 0;
        
        System.out.println("===== 雇员管理系统 =====");
        
        do {
            // 功能选择界面
            System.out.println("\n请选择功能：");
            System.out.println("1. 雇员信息录入");
            System.out.println("2. 雇员信息查看和编辑");
            System.out.println("3. 雇员信息查询");
            System.out.println("4. 雇员信息删除");
            System.out.println("5. 薪资管理");
            System.out.println("0. 退出程序");
            System.out.print("请选择：");
            
            try {
                option = scanner.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("\n错误：请输入数字选项！");
                scanner.nextLine(); // 清除无效输入
                continue; // 跳过当前循环，重新显示菜单
            }
            scanner.nextLine(); // 清除缓冲区换行符
            
            switch(option) {
                case 1: // 雇员信息录入
                    try {
                        System.out.print("请输入员工姓名：");
                        String name = scanner.nextLine();
                        System.out.print("请输入员工职务：");
                        String position = scanner.nextLine();
                        
                        int leaveDays = 0;
                        while (true) {
                            try {
                                System.out.print("请输入请假天数：");
                                leaveDays = scanner.nextInt();
                                scanner.nextLine(); // 清除换行符
                                break;
                            } catch (InputMismatchException e) {
                                System.out.println("错误：请输入有效的数字！");
                                scanner.nextLine(); // 清除无效输入
                            }
                        }
                        
                        double basicSalary = 0.0;
                        while (true) {
                            try {
                                System.out.print("请输入基本工资：");
                                basicSalary = scanner.nextDouble();
                                scanner.nextLine(); // 清除换行符
                                break;
                            } catch (InputMismatchException e) {
                                System.out.println("错误：请输入有效的数字！");
                                scanner.nextLine(); // 清除无效输入
                            }
                        }
                        
                        Employee newEmployee = new Employee(nextId++, name, position, leaveDays, basicSalary);
                        employees.add(newEmployee);
                        System.out.println("\n----已完成雇员信息录入-----");
                        System.out.println("雇员信息录入成功！ID: " + newEmployee.id);
                    } catch (Exception e) {
                        System.out.println("发生错误：" + e.getMessage());
                        scanner.nextLine(); // 清除可能的无效输入
                    }
                    break;
                    
                case 2: // 雇员信息查看和编辑
                    try {
                        int editId = 0;
                        while (true) {
                            try {
                                System.out.print("请输入要查看和编辑的雇员ID：");
                                editId = scanner.nextInt();
                                scanner.nextLine(); // 清除换行符
                                break;
                            } catch (InputMismatchException e) {
                                System.out.println("错误：请输入有效的数字ID！");
                                scanner.nextLine(); // 清除无效输入
                            }
                        }
                        
                        Employee editEmp = null;
                        for (Employee emp : employees) {
                            if (emp.id == editId) {
                                editEmp = emp;
                                break;
                            }
                        }
                        
                        if (editEmp == null) {
                            System.out.println("未找到ID为 " + editId + " 的雇员！");
                            break;
                        }
                        
                        // 显示当前信息
                        System.out.println("\n当前雇员信息：");
                        System.out.println("ID: " + editEmp.id);
                        System.out.println("姓名: " + editEmp.name);
                        System.out.println("职务: " + editEmp.position);
                        System.out.println("请假天数: " + editEmp.leaveDays);
                        System.out.println("基本工资: " + editEmp.basicSalary);
                        
                        // 编辑信息
                        System.out.println("\n请输入新的信息（直接回车保留原值）:");
                        System.out.print("姓名(" + editEmp.name + "): ");
                        String newName = scanner.nextLine();
                        if (!newName.isEmpty()) editEmp.name = newName;
                        
                        System.out.print("职务(" + editEmp.position + "): ");
                        String newPosition = scanner.nextLine();
                        if (!newPosition.isEmpty()) editEmp.position = newPosition;
                        
                        System.out.print("请假天数(" + editEmp.leaveDays + "): ");
                        String leaveInput = scanner.nextLine();
                        if (!leaveInput.isEmpty()) {
                            try {
                                editEmp.leaveDays = Integer.parseInt(leaveInput);
                            } catch (NumberFormatException e) {
                                System.out.println("错误：输入的不是有效数字，请假天数保持不变！");
                            }
                        }
                        
                        System.out.print("基本工资(" + editEmp.basicSalary + "): ");
                        String salaryInput = scanner.nextLine();
                        if (!salaryInput.isEmpty()) {
                            try {
                                editEmp.basicSalary = Double.parseDouble(salaryInput);
                            } catch (NumberFormatException e) {
                                System.out.println("错误：输入的不是有效数字，基本工资保持不变！");
                            }
                        }
                        
                        System.out.println("\n----已完成雇员信息编辑-----");
                        System.out.println("雇员信息已更新！");
                    } catch (Exception e) {
                        System.out.println("发生错误：" + e.getMessage());
                        scanner.nextLine(); // 清除可能的无效输入
                    }
                    break;
                    
                case 3: // 雇员信息查询
                    try {
                        System.out.println("\n请选择查询方式：");
                        System.out.println("1. 按ID查询");
                        System.out.println("2. 按姓名查询");
                        System.out.print("请选择：");
                        
                        int searchOption = 0;
                        while (true) {
                            try {
                                searchOption = scanner.nextInt();
                                scanner.nextLine(); // 清除换行符
                                break;
                            } catch (InputMismatchException e) {
                                System.out.println("错误：请输入有效的数字选项！");
                                scanner.nextLine(); // 清除无效输入
                            }
                        }
                        
                        if (searchOption == 1) {
                            int searchId = 0;
                            while (true) {
                                try {
                                    System.out.print("请输入雇员ID：");
                                    searchId = scanner.nextInt();
                                    scanner.nextLine();
                                    break;
                                } catch (InputMismatchException e) {
                                    System.out.println("错误：请输入有效的数字ID！");
                                    scanner.nextLine(); // 清除无效输入
                                }
                            }
                            
                            boolean found = false;
                            for (Employee emp : employees) {
                                if (emp.id == searchId) {
                                    displayEmployee(emp);
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                System.out.println("未找到ID为 " + searchId + " 的雇员！");
                            }
                        } else if (searchOption == 2) {
                            System.out.print("请输入雇员姓名：");
                            String searchName = scanner.nextLine();
                            
                            boolean found = false;
                            for (Employee emp : employees) {
                                if (emp.name.equalsIgnoreCase(searchName)) {
                                    displayEmployee(emp);
                                    found = true;
                                }
                            }
                            if (!found) {
                                System.out.println("未找到姓名为 " + searchName + " 的雇员！");
                            }
                        } else {
                            System.out.println("无效的选择！");
                        }
                        System.out.println("----已完成雇员信息的查询-----");
                    } catch (Exception e) {
                        System.out.println("发生错误：" + e.getMessage());
                        scanner.nextLine(); // 清除可能的无效输入
                    }
                    break;
                    
                case 4: // 雇员信息删除
                    try {
                        int deleteId = 0;
                        while (true) {
                            try {
                                System.out.print("请输入要删除的雇员ID：");
                                deleteId = scanner.nextInt();
                                scanner.nextLine();
                                break;
                            } catch (InputMismatchException e) {
                                System.out.println("错误：请输入有效的数字ID！");
                                scanner.nextLine(); // 清除无效输入
                            }
                        }
                        
                        boolean removed = false;
                        for (int i = 0; i < employees.size(); i++) {
                            if (employees.get(i).id == deleteId) {
                                employees.remove(i);
                                removed = true;
                                break;
                            }
                        }
                        
                        if (removed) {
                            System.out.println("ID为 " + deleteId + " 的雇员信息已删除！");
                        } else {
                            System.out.println("未找到ID为 " + deleteId + " 的雇员！");
                        }
                        System.out.println("----已完成雇员信息删除-----");
                    } catch (Exception e) {
                        System.out.println("发生错误：" + e.getMessage());
                        scanner.nextLine(); // 清除可能的无效输入
                    }
                    break;
                    
                case 5: // 薪资管理
                    try {
                        int salaryId = 0;
                        while (true) {
                            try {
                                System.out.print("请输入要调整薪资的雇员ID：");
                                salaryId = scanner.nextInt();
                                scanner.nextLine();
                                break;
                            } catch (InputMismatchException e) {
                                System.out.println("错误：请输入有效的数字ID！");
                                scanner.nextLine(); // 清除无效输入
                            }
                        }
                        
                        Employee salaryEmp = null;
                        for (Employee emp : employees) {
                            if (emp.id == salaryId) {
                                salaryEmp = emp;
                                break;
                            }
                        }
                        
                        if (salaryEmp == null) {
                            System.out.println("未找到ID为 " + salaryId + " 的雇员！");
                            break;
                        }
                        
                        System.out.println("当前薪资: " + salaryEmp.basicSalary);
                        
                        double newSalary = 0.0;
                        while (true) {
                            try {
                                System.out.print("请输入新的薪资：");
                                newSalary = scanner.nextDouble();
                                scanner.nextLine();
                                break;
                            } catch (InputMismatchException e) {
                                System.out.println("错误：请输入有效的数字！");
                                scanner.nextLine(); // 清除无效输入
                            }
                        }
                        
                        salaryEmp.basicSalary = newSalary;
                        System.out.println("薪资已更新为: " + newSalary);
                        System.out.println("----已完成雇员薪资管理-----");
                    } catch (Exception e) {
                        System.out.println("发生错误：" + e.getMessage());
                        scanner.nextLine(); // 清除可能的无效输入
                    }
                    break;
                    
                case 0: // 退出程序
                    System.out.println("正在退出程序...");
                    break;
                    
                default:
                    System.out.println("无效的选择，请重新输入！");
            }
        } while(option != 0);
        
        scanner.close();
        System.out.println("程序已退出");
    }
    
    // 显示雇员信息的方法
    private static void displayEmployee(Employee emp) {
        System.out.println("\n雇员信息：");
        System.out.println("ID: " + emp.id);
        System.out.println("姓名: " + emp.name);
        System.out.println("职务: " + emp.position);
        System.out.println("请假天数: " + emp.leaveDays);
        System.out.println("基本工资: " + emp.basicSalary);
    }
}