import java.awt.*;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class BookManager {
    private static final String BOOK_FILE = "books.csv";
    private static final String BORROW_FILE = "borrow_records.csv";

    public JPanel createBookManagementPanel(String currentUser, String currentRole) {
        JPanel panel = new JPanel(new BorderLayout());

        // 图书列表
        String[] columnNames = {"图书ID", "书名", "作者", "状态", "借阅者"};
        DefaultTableModel tableModel = new DefaultTableModel(columnNames, 0);
        JTable bookTable = new JTable(tableModel);

        loadBookData(tableModel);

        JScrollPane scrollPane = new JScrollPane(bookTable);
        panel.add(scrollPane, BorderLayout.CENTER);

        // 按钮面板
        JPanel buttonPanel = new JPanel();
        JButton refreshButton = new JButton("刷新");
        JButton borrowButton = new JButton("借书");
        JButton returnButton = new JButton("还书");

        refreshButton.addActionListener(e -> loadBookData(tableModel));

        borrowButton.addActionListener(e -> {
            int selectedRow = bookTable.getSelectedRow();
            if (selectedRow >= 0) {
                String bookId = (String) tableModel.getValueAt(selectedRow, 0);
                String status = (String) tableModel.getValueAt(selectedRow, 3);

                if ("可借".equals(status)) {
                    if (borrowBook(bookId, currentUser)) {
                        JOptionPane.showMessageDialog(panel, "借书成功！");
                        loadBookData(tableModel);
                    } else {
                        JOptionPane.showMessageDialog(panel, "借书失败！");
                    }
                } else {
                    JOptionPane.showMessageDialog(panel, "该书籍已被借出！");
                }
            } else {
                JOptionPane.showMessageDialog(panel, "请选择要借阅的图书！");
            }
        });

        returnButton.addActionListener(e -> {
            int selectedRow = bookTable.getSelectedRow();
            if (selectedRow >= 0) {
                String bookId = (String) tableModel.getValueAt(selectedRow, 0);
                String borrower = (String) tableModel.getValueAt(selectedRow, 4);

                if (currentUser.equals(borrower) || "管理员".equals(currentRole)) {
                    if (returnBook(bookId)) {
                        JOptionPane.showMessageDialog(panel, "还书成功！");
                        loadBookData(tableModel);
                    } else {
                        JOptionPane.showMessageDialog(panel, "还书失败！");
                    }
                } else {
                    JOptionPane.showMessageDialog(panel, "您没有权限还这本书！");
                }
            } else {
                JOptionPane.showMessageDialog(panel, "请选择要归还的图书！");
            }
        });

        buttonPanel.add(refreshButton);
        buttonPanel.add(borrowButton);
        buttonPanel.add(returnButton);

        if ("管理员".equals(currentRole)) {
            JButton addButton = new JButton("添加图书");
            JButton deleteButton = new JButton("删除图书");

            addButton.addActionListener(e -> showAddBookDialog(panel, tableModel));

            deleteButton.addActionListener(e -> {
                int selectedRow = bookTable.getSelectedRow();
                if (selectedRow >= 0) {
                    String bookId = (String) tableModel.getValueAt(selectedRow, 0);
                    int result = JOptionPane.showConfirmDialog(panel,
                            "确定要删除图书 " + bookId + " 吗？");
                    if (result == JOptionPane.YES_OPTION) {
                        deleteBook(bookId);
                        loadBookData(tableModel);
                    }
                } else {
                    JOptionPane.showMessageDialog(panel, "请选择要删除的图书！");
                }
            });

            buttonPanel.add(addButton);
            buttonPanel.add(deleteButton);
        }

        panel.add(buttonPanel, BorderLayout.SOUTH);

        return panel;
    }

    private void loadBookData(DefaultTableModel tableModel) {
        tableModel.setRowCount(0);
        try (BufferedReader br = new BufferedReader(new FileReader(BOOK_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 4) {
                    String borrower = parts.length > 4 ? parts[4] : "";
                    tableModel.addRow(new Object[]{parts[0], parts[1], parts[2], parts[3], borrower});
                }
            }
        } catch (IOException e) {
            // 文件不存在时创建示例图书
            createSampleBooks();
            loadBookData(tableModel);
        }
    }

    private void createSampleBooks() {
        try (PrintWriter pw = new PrintWriter(new FileWriter(BOOK_FILE))) {
            pw.println("B001,Java编程思想,Bruce Eckel,可借,");
            pw.println("B002,Python核心编程,Wesley Chun,可借,");
            pw.println("B003,算法导论,Thomas Cormen,可借,");
            pw.println("B004,数据结构与算法分析,Mark Weiss,可借,");
            pw.println("B005,计算机网络,Andrew Tanenbaum,可借,");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private boolean borrowBook(String bookId, String borrower) {
        List<String> lines = new ArrayList<>();
        boolean success = false;

        try (BufferedReader br = new BufferedReader(new FileReader(BOOK_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 4 && parts[0].equals(bookId) && "可借".equals(parts[3])) {
                    parts[3] = "已借";
                    if (parts.length > 4) {
                        parts[4] = borrower;
                    } else {
                        line = line + "," + borrower;
                    }
                    line = String.join(",", parts);
                    success = true;

                    // 记录借阅记录
                    recordBorrow(bookId, borrower);
                }
                lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }

        if (success) {
            try (PrintWriter pw = new PrintWriter(new FileWriter(BOOK_FILE))) {
                for (String line : lines) {
                    pw.println(line);
                }
            } catch (IOException e) {
                e.printStackTrace();
                return false;
            }
        }

        return success;
    }

    private boolean returnBook(String bookId) {
        List<String> lines = new ArrayList<>();
        boolean success = false;

        try (BufferedReader br = new BufferedReader(new FileReader(BOOK_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 4 && parts[0].equals(bookId) && "已借".equals(parts[3])) {
                    parts[3] = "可借";
                    if (parts.length > 4) {
                        parts[4] = "";
                    }
                    line = String.join(",", parts);
                    success = true;

                    // 记录归还记录
                    recordReturn(bookId);
                }
                lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }

        if (success) {
            try (PrintWriter pw = new PrintWriter(new FileWriter(BOOK_FILE))) {
                for (String line : lines) {
                    pw.println(line);
                }
            } catch (IOException e) {
                e.printStackTrace();
                return false;
            }
        }

        return success;
    }

    private void recordBorrow(String bookId, String borrower) {
        try (PrintWriter pw = new PrintWriter(new FileWriter(BORROW_FILE, true))) {
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
            pw.println(bookId + "," + borrower + "," + sdf.format(new Date()) + ",借出,");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void recordReturn(String bookId) {
        try (PrintWriter pw = new PrintWriter(new FileWriter(BORROW_FILE, true))) {
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
            pw.println(bookId + ",," + sdf.format(new Date()) + ",归还,");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void showAddBookDialog(JPanel parent, DefaultTableModel tableModel) {
        JDialog dialog = new JDialog((Frame) SwingUtilities.getWindowAncestor(parent), "添加图书", true);
        dialog.setSize(400, 300);
        dialog.setLocationRelativeTo(parent);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        gbc.gridx = 0; gbc.gridy = 0;
        panel.add(new JLabel("图书ID:"), gbc);

        JTextField idField = new JTextField(15);
        gbc.gridx = 1; gbc.gridy = 0;
        panel.add(idField, gbc);

        gbc.gridx = 0; gbc.gridy = 1;
        panel.add(new JLabel("书名:"), gbc);

        JTextField titleField = new JTextField(15);
        gbc.gridx = 1; gbc.gridy = 1;
        panel.add(titleField, gbc);

        gbc.gridx = 0; gbc.gridy = 2;
        panel.add(new JLabel("作者:"), gbc);

        JTextField authorField = new JTextField(15);
        gbc.gridx = 1; gbc.gridy = 2;
        panel.add(authorField, gbc);

        JButton confirmButton = new JButton("确认添加");
        JButton cancelButton = new JButton("取消");

        gbc.gridx = 0; gbc.gridy = 3;
        panel.add(confirmButton, gbc);
        gbc.gridx = 1; gbc.gridy = 3;
        panel.add(cancelButton, gbc);

        confirmButton.addActionListener(e -> {
            String id = idField.getText().trim();
            String title = titleField.getText().trim();
            String author = authorField.getText().trim();

            if (!id.isEmpty() && !title.isEmpty() && !author.isEmpty()) {
                if (addBook(id, title, author)) {
                    JOptionPane.showMessageDialog(dialog, "添加成功！");
                    loadBookData(tableModel);
                    dialog.dispose();
                } else {
                    JOptionPane.showMessageDialog(dialog, "添加失败，图书ID已存在！");
                }
            } else {
                JOptionPane.showMessageDialog(dialog, "请填写完整信息！");
            }
        });

        cancelButton.addActionListener(e -> dialog.dispose());

        dialog.add(panel);
        dialog.setVisible(true);
    }

    private boolean addBook(String id, String title, String author) {
        // 检查ID是否已存在
        try (BufferedReader br = new BufferedReader(new FileReader(BOOK_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 1 && parts[0].equals(id)) {
                    return false;
                }
            }
        } catch (IOException e) {
            // 文件不存在，继续添加
        }

        try (PrintWriter pw = new PrintWriter(new FileWriter(BOOK_FILE, true))) {
            pw.println(id + "," + title + "," + author + ",可借,");
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

    private void deleteBook(String bookId) {
        List<String> lines = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(BOOK_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 1 && !parts[0].equals(bookId)) {
                    lines.add(line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        try (PrintWriter pw = new PrintWriter(new FileWriter(BOOK_FILE))) {
            for (String line : lines) {
                pw.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}