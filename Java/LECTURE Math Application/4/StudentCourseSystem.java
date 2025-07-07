import java.util.*;

class Course {
    private String courseName;
    private String teacher;
    private String classTime;

    public Course(String courseName, String teacher, String classTime) {
        this.courseName = courseName;
        this.teacher = teacher;
        this.classTime = classTime;
    }

    // getter和setter方法
    public String getCourseName() { return courseName; }
    public void setCourseName(String courseName) { this.courseName = courseName; }

    public String getTeacher() { return teacher; }
    public void setTeacher(String teacher) { this.teacher = teacher; }

    public String getClassTime() { return classTime; }
    public void setClassTime(String classTime) { this.classTime = classTime; }

    @Override
    public String toString() {
        return "课程名称：" + courseName + ", 授课老师：" + teacher + ", 上课时间：" + classTime;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Course course = (Course) obj;
        return Objects.equals(courseName, course.courseName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(courseName);
    }
}

class Student {
    private String name;
    private int age;
    private List<Course> selectedCourses;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
        this.selectedCourses = new ArrayList<>();
    }

    // getter和setter方法
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public int getAge() { return age; }
    public void setAge(int age) { this.age = age; }

    public List<Course> getSelectedCourses() { return selectedCourses; }

    // 选择课程
    public boolean selectCourse(Course course) {
        if (selectedCourses.contains(course)) {
            return false; // 已经选择过该课程
        }
        selectedCourses.add(course);
        return true;
    }

    // 取消选课
    public boolean removeCourse(Course course) {
        return selectedCourses.remove(course);
    }

    // 显示学生信息
    public void displayInfo() {
        System.out.println("学生姓名：" + name);
        System.out.println("学生年龄：" + age);
        System.out.println("所选课程：");
        if (selectedCourses.isEmpty()) {
            System.out.println("  暂无选课");
        } else {
            for (int i = 0; i < selectedCourses.size(); i++) {
                System.out.println("  " + (i + 1) + ". " + selectedCourses.get(i));
            }
        }
    }
}

public class StudentCourseSystem {
    private static List<Student> students = new ArrayList<>();
    private static List<Course> courses = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        initializeCourses(); // 初始化一些课程

        while (true) {
            showMenu();
            int choice = getValidChoice();

            switch (choice) {
                case 1:
                    createStudent();
                    break;
                case 2:
                    createCourse();
                    break;
                case 3:
                    selectCourseForStudent();
                    break;
                case 4:
                    modifyStudentCourse();
                    break;
                case 5:
                    displayStudentInfo();
                    break;
                case 6:
                    displayAllCourses();
                    break;
                case 0:
                    System.out.println("结束。");
                    return;
                default:
                    System.out.println("无效的选择，请重新输入。");
            }
        }
    }

    private static void initializeCourses() {
        // courses.add(new Course(courseName, teacher, classTime));
    }

    private static void showMenu() {
        System.out.println("\n=== 学生选课系统 ===");
        System.out.println("1. 创建学生");
        System.out.println("2. 创建课程");
        System.out.println("3. 学生选课");
        System.out.println("4. 修改选课");
        System.out.println("5. 显示学生信息");
        System.out.println("6. 显示所有课程");
        System.out.println("0. 退出系统");
        System.out.print("请选择操作：");
    }

    private static int getValidChoice() {
        while (true) {
            try {
                String input = scanner.nextLine().trim();
                if (input.isEmpty()) {
                    System.out.print("输入不能为空，请重新输入：");
                    continue;
                }
                int choice = Integer.parseInt(input);
                if (choice >= 0 && choice <= 6) {
                    return choice;
                } else {
                    System.out.print("请输入0-6之间的数字：");
                }
            } catch (NumberFormatException e) {
                System.out.print("请输入有效的数字：");
            }
        }
    }

    private static void createStudent() {
        System.out.print("请输入学生姓名：");
        String name = scanner.nextLine().trim();

        if (name.isEmpty()) {
            System.out.println("学生姓名不能为空！");
            return;
        }

        // 检查是否已存在同名学生
        for (Student student : students) {
            if (student.getName().equals(name)) {
                System.out.println("已存在同名学生！");
                return;
            }
        }

        int age = getValidAge();
        if (age == -1) return;

        Student student = new Student(name, age);
        students.add(student);
        System.out.println("学生创建成功！");
    }

    private static int getValidAge() {
        while (true) {
            try {
                System.out.print("请输入学生年龄：");
                String input = scanner.nextLine().trim();
                if (input.isEmpty()) {
                    System.out.println("年龄不能为空！");
                    continue;
                }
                int age = Integer.parseInt(input);
                if (age >= 0 ) {
                    return age;
                } else {
                    System.out.println("年龄必须大于0！");
                }
            } catch (NumberFormatException e) {
                System.out.println("请输入有效的数字！");
            }
        }
    }

    private static void createCourse() {
        System.out.print("请输入课程名称：");
        String courseName = scanner.nextLine().trim();

        if (courseName.isEmpty()) {
            System.out.println("课程名称不能为空！");
            return;
        }

        // 检查是否已存在同名课程
        for (Course course : courses) {
            if (course.getCourseName().equals(courseName)) {
                System.out.println("已存在同名课程！");
                return;
            }
        }

        System.out.print("请输入授课老师：");
        String teacher = scanner.nextLine().trim();
        if (teacher.isEmpty()) {
            System.out.println("授课老师不能为空！");
            return;
        }

        System.out.print("请输入上课时间：");
        String classTime = scanner.nextLine().trim();
        if (classTime.isEmpty()) {
            System.out.println("上课时间不能为空！");
            return;
        }

        Course course = new Course(courseName, teacher, classTime);
        courses.add(course);
        System.out.println("课程创建成功！");
    }

    private static void selectCourseForStudent() {
        if (students.isEmpty()) {
            System.out.println("暂无学生，请先创建学生！");
            return;
        }

        if (courses.isEmpty()) {
            System.out.println("暂无课程，请先创建课程！");
            return;
        }

        Student student = selectStudent();
        if (student == null) return;

        Course course = selectCourse();
        if (course == null) return;

        if (student.selectCourse(course)) {
            System.out.println("选课成功！");
        } else {
            System.out.println("该学生已经选择过这门课程！");
        }
    }

    private static void modifyStudentCourse() {
        if (students.isEmpty()) {
            System.out.println("暂无学生，请先创建学生！");
            return;
        }

        Student student = selectStudent();
        if (student == null) return;

        if (student.getSelectedCourses().isEmpty()) {
            System.out.println("该学生暂无选课记录！");
            return;
        }

        System.out.println("该学生的选课情况：");
        List<Course> selectedCourses = student.getSelectedCourses();
        for (int i = 0; i < selectedCourses.size(); i++) {
            System.out.println((i + 1) + ". " + selectedCourses.get(i));
        }

        System.out.print("请选择要取消的课程编号（输入0返回）：");
        int choice = getValidCourseChoice(selectedCourses.size());
        if (choice == 0) return;

        Course courseToRemove = selectedCourses.get(choice - 1);
        student.removeCourse(courseToRemove);
        System.out.println("取消选课成功！");
    }

    private static int getValidCourseChoice(int maxChoice) {
        while (true) {
            try {
                String input = scanner.nextLine().trim();
                if (input.isEmpty()) {
                    System.out.print("输入不能为空，请重新输入：");
                    continue;
                }
                int choice = Integer.parseInt(input);
                if (choice >= 0 && choice <= maxChoice) {
                    return choice;
                } else {
                    System.out.print("请输入0-" + maxChoice + "之间的数字：");
                }
            } catch (NumberFormatException e) {
                System.out.print("请输入有效的数字：");
            }
        }
    }

    private static Student selectStudent() {
        System.out.println("学生列表：");
        for (int i = 0; i < students.size(); i++) {
            System.out.println((i + 1) + ". " + students.get(i).getName() +
                    " (年龄：" + students.get(i).getAge() + ")");
        }

        System.out.print("请选择学生编号（输入0返回）：");
        int choice = getValidCourseChoice(students.size());
        if (choice == 0) return null;

        return students.get(choice - 1);
    }

    private static Course selectCourse() {
        System.out.println("课程列表：");
        for (int i = 0; i < courses.size(); i++) {
            System.out.println((i + 1) + ". " + courses.get(i));
        }

        System.out.print("请选择课程编号（输入0返回）：");
        int choice = getValidCourseChoice(courses.size());
        if (choice == 0) return null;

        return courses.get(choice - 1);
    }

    private static void displayStudentInfo() {
        if (students.isEmpty()) {
            System.out.println("暂无学生，请先创建学生！");
            return;
        }

        Student student = selectStudent();
        if (student == null) return;

        System.out.println("\n=== 学生详细信息 ===");
        student.displayInfo();
    }

    private static void displayAllCourses() {
        if (courses.isEmpty()) {
            System.out.println("暂无课程！");
            return;
        }

        System.out.println("\n=== 所有课程信息 ===");
        for (int i = 0; i < courses.size(); i++) {
            System.out.println((i + 1) + ". " + courses.get(i));
        }
    }
}