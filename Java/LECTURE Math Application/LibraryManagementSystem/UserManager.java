import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class UserManager {
    private static final String USER_FILE = "users.csv";

    public String login(String username, String password) {
        try (BufferedReader br = new BufferedReader(new FileReader(USER_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 3 && parts[0].equals(username) && parts[1].equals(password)) {
                    return parts[2];
                }
            }
        } catch (IOException e) {
            // 文件不存在时创建默认管理员账户
            if (!new File(USER_FILE).exists()) {
                try (PrintWriter pw = new PrintWriter(new FileWriter(USER_FILE))) {
                    pw.println("admin,123456,管理员");
                    if (username.equals("admin") && password.equals("123456")) {
                        return "管理员";
                    }
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        }
        return null;
    }

    public boolean register(String username, String password, String role) {
        // 检查用户名是否已存在
        try (BufferedReader br = new BufferedReader(new FileReader(USER_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 1 && parts[0].equals(username)) {
                    return false; // 用户名已存在
                }
            }
        } catch (IOException e) {
            // 文件不存在，继续注册
        }

        // 添加新用户
        try (PrintWriter pw = new PrintWriter(new FileWriter(USER_FILE, true))) {
            pw.println(username + "," + password + "," + role);
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

    public JPanel createUserManagementPanel() {
        JPanel panel = new JPanel(new BorderLayout());

        // 用户列表
        String[] columnNames = {"用户名", "角色"};
        DefaultTableModel tableModel = new DefaultTableModel(columnNames, 0);
        JTable userTable = new JTable(tableModel);

        loadUserData(tableModel);

        JScrollPane scrollPane = new JScrollPane(userTable);
        panel.add(scrollPane, BorderLayout.CENTER);

        // 按钮面板
        JPanel buttonPanel = new JPanel();
        JButton refreshButton = new JButton("刷新");
        JButton deleteButton = new JButton("删除用户");

        refreshButton.addActionListener(e -> loadUserData(tableModel));

        deleteButton.addActionListener(e -> {
            int selectedRow = userTable.getSelectedRow();
            if (selectedRow >= 0) {
                String username = (String) tableModel.getValueAt(selectedRow, 0);
                int result = JOptionPane.showConfirmDialog(panel,
                        "确定要删除用户 " + username + " 吗？");
                if (result == JOptionPane.YES_OPTION) {
                    deleteUser(username);
                    loadUserData(tableModel);
                }
            } else {
                JOptionPane.showMessageDialog(panel, "请选择要删除的用户！");
            }
        });

        buttonPanel.add(refreshButton);
        buttonPanel.add(deleteButton);
        panel.add(buttonPanel, BorderLayout.SOUTH);

        return panel;
    }

    private void loadUserData(DefaultTableModel tableModel) {
        tableModel.setRowCount(0);
        try (BufferedReader br = new BufferedReader(new FileReader(USER_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 3) {
                    tableModel.addRow(new Object[]{parts[0], parts[2]});
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void deleteUser(String username) {
        List<String> lines = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(USER_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 1 && !parts[0].equals(username)) {
                    lines.add(line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        try (PrintWriter pw = new PrintWriter(new FileWriter(USER_FILE))) {
            for (String line : lines) {
                pw.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}