import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PythonAPI {

    public static void generateBorrowRanking() throws IOException, InterruptedException {
        executePythonScript("borrow_ranking.py");
    }

    public static void generateTrendChart() throws IOException, InterruptedException {
        executePythonScript("trend_chart.py");
    }

    public static void sendOverdueNotifications() throws IOException, InterruptedException {
        executePythonScript("email_notification.py");
    }

    private static void executePythonScript(String scriptName) throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("python", scriptName);
        pb.redirectErrorStream(true);
        Process process = pb.start();

        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            System.out.println(line);
        }

        int exitCode = process.waitFor();
        if (exitCode != 0) {
            throw new RuntimeException("Python script execution failed with exit code: " + exitCode);
        }
    }
}