import java.awt.*;
import javax.swing.*;

public class LibraryManagementSystem extends JFrame {
    private UserManager userManager;
    private BookManager bookManager;
    private String currentUser;
    private String currentRole;

    public LibraryManagementSystem() {
        userManager = new UserManager();
        bookManager = new BookManager();
        initializeGUI();
    }

    private void initializeGUI() {
        setTitle("图书管理系统");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 600);
        setLocationRelativeTo(null);

        showLoginDialog();
    }

    private void showLoginDialog() {
        JDialog loginDialog = new JDialog(this, "用户登录", true);
        loginDialog.setSize(400, 300);
        loginDialog.setLocationRelativeTo(this);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        JLabel titleLabel = new JLabel("图书管理系统登录");
        titleLabel.setFont(new Font("宋体", Font.BOLD, 18));
        gbc.gridx = 0; gbc.gridy = 0; gbc.gridwidth = 2;
        gbc.insets = new Insets(20, 0, 20, 0);
        panel.add(titleLabel, gbc);

        gbc.gridwidth = 1;
        gbc.insets = new Insets(5, 5, 5, 5);

        gbc.gridx = 0; gbc.gridy = 1;
        panel.add(new JLabel("用户名:"), gbc);

        JTextField usernameField = new JTextField(15);
        gbc.gridx = 1; gbc.gridy = 1;
        panel.add(usernameField, gbc);

        gbc.gridx = 0; gbc.gridy = 2;
        panel.add(new JLabel("密码:"), gbc);

        JPasswordField passwordField = new JPasswordField(15);
        gbc.gridx = 1; gbc.gridy = 2;
        panel.add(passwordField, gbc);

        JButton loginButton = new JButton("登录");
        JButton registerButton = new JButton("注册");

        gbc.gridx = 0; gbc.gridy = 3;
        panel.add(loginButton, gbc);
        gbc.gridx = 1; gbc.gridy = 3;
        panel.add(registerButton, gbc);

        loginButton.addActionListener(e -> {
            String username = usernameField.getText();
            String password = new String(passwordField.getPassword());

            String role = userManager.login(username, password);
            if (role != null) {
                currentUser = username;
                currentRole = role;
                loginDialog.dispose();
                createMainInterface();
            } else {
                JOptionPane.showMessageDialog(loginDialog, "用户名或密码错误！");
            }
        });

        registerButton.addActionListener(e -> showRegisterDialog(loginDialog));

        loginDialog.add(panel);
        loginDialog.setVisible(true);
    }

    private void showRegisterDialog(JDialog parent) {
        JDialog registerDialog = new JDialog(parent, "用户注册", true);
        registerDialog.setSize(400, 350);
        registerDialog.setLocationRelativeTo(parent);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        gbc.gridx = 0; gbc.gridy = 0;
        panel.add(new JLabel("用户名:"), gbc);

        JTextField usernameField = new JTextField(15);
        gbc.gridx = 1; gbc.gridy = 0;
        panel.add(usernameField, gbc);

        gbc.gridx = 0; gbc.gridy = 1;
        panel.add(new JLabel("密码:"), gbc);

        JPasswordField passwordField = new JPasswordField(15);
        gbc.gridx = 1; gbc.gridy = 1;
        panel.add(passwordField, gbc);

        gbc.gridx = 0; gbc.gridy = 2;
        panel.add(new JLabel("角色:"), gbc);

        String[] roles = {"学生", "管理员"};
        JComboBox<String> roleCombo = new JComboBox<>(roles);
        gbc.gridx = 1; gbc.gridy = 2;
        panel.add(roleCombo, gbc);

        JButton confirmButton = new JButton("确认注册");
        JButton cancelButton = new JButton("取消");

        gbc.gridx = 0; gbc.gridy = 3;
        panel.add(confirmButton, gbc);
        gbc.gridx = 1; gbc.gridy = 3;
        panel.add(cancelButton, gbc);

        confirmButton.addActionListener(e -> {
            String username = usernameField.getText();
            String password = new String(passwordField.getPassword());
            String role = (String) roleCombo.getSelectedItem();

            if (userManager.register(username, password, role)) {
                JOptionPane.showMessageDialog(registerDialog, "注册成功！");
                registerDialog.dispose();
            } else {
                JOptionPane.showMessageDialog(registerDialog, "注册失败，用户名已存在！");
            }
        });

        cancelButton.addActionListener(e -> registerDialog.dispose());

        registerDialog.add(panel);
        registerDialog.setVisible(true);
    }

    private void createMainInterface() {
        getContentPane().removeAll();
        setLayout(new BorderLayout());

        // 标题栏
        JPanel titlePanel = new JPanel();
        titlePanel.setBackground(new Color(70, 130, 180));
        JLabel titleLabel = new JLabel("图书管理系统 - 欢迎 " + currentUser + " (" + currentRole + ")");
        titleLabel.setForeground(Color.WHITE);
        titleLabel.setFont(new Font("宋体", Font.BOLD, 16));
        titlePanel.add(titleLabel);
        add(titlePanel, BorderLayout.NORTH);

        // 主要内容区域
        JTabbedPane tabbedPane = new JTabbedPane();

        // 图书管理选项卡
        tabbedPane.addTab("图书管理", createBookManagementPanel());

        // 数据统计选项卡
        tabbedPane.addTab("数据统计", createStatisticsPanel());

        if ("管理员".equals(currentRole)) {
            // 用户管理选项卡（仅管理员可见）
            tabbedPane.addTab("用户管理", createUserManagementPanel());
        }

        add(tabbedPane, BorderLayout.CENTER);

        // 底部按钮
        JPanel buttonPanel = new JPanel();
        JButton logoutButton = new JButton("退出登录");
        logoutButton.addActionListener(e -> {
            int result = JOptionPane.showConfirmDialog(this, "确定要退出登录吗？");
            if (result == JOptionPane.YES_OPTION) {
                dispose();
                new LibraryManagementSystem();
            }
        });
        buttonPanel.add(logoutButton);
        add(buttonPanel, BorderLayout.SOUTH);

        revalidate();
        repaint();
        setVisible(true);
    }

    private JPanel createBookManagementPanel() {
        return bookManager.createBookManagementPanel(currentUser, currentRole);
    }

    private JPanel createStatisticsPanel() {
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);

        JButton borrowRankingButton = new JButton("生成借阅排行榜(Top10)");
        JButton trendChartButton = new JButton("生成借阅趋势图");
        JButton overdueNotifyButton = new JButton("发送到期提醒邮件");

        gbc.gridx = 0; gbc.gridy = 0;
        panel.add(borrowRankingButton, gbc);

        gbc.gridx = 0; gbc.gridy = 1;
        panel.add(trendChartButton, gbc);

        gbc.gridx = 0; gbc.gridy = 2;
        panel.add(overdueNotifyButton, gbc);

        borrowRankingButton.addActionListener(e -> {
            try {
                PythonAPI.generateBorrowRanking();
                JOptionPane.showMessageDialog(this, "借阅排行榜已生成！");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "生成失败：" + ex.getMessage());
            }
        });

        trendChartButton.addActionListener(e -> {
            try {
                PythonAPI.generateTrendChart();
                JOptionPane.showMessageDialog(this, "借阅趋势图已生成！");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "生成失败：" + ex.getMessage());
            }
        });

        overdueNotifyButton.addActionListener(e -> {
            try {
                PythonAPI.sendOverdueNotifications();
                JOptionPane.showMessageDialog(this, "到期提醒邮件已发送！");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "发送失败：" + ex.getMessage());
            }
        });

        return panel;
    }

    private JPanel createUserManagementPanel() {
        return userManager.createUserManagementPanel();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            try {
                UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            } catch (Exception e) {
                e.printStackTrace();
            }
            new LibraryManagementSystem();
        });
    }
}