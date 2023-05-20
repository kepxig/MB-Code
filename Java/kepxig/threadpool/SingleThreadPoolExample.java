
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SingleThreadPoolExample {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newSingleThreadExecutor();
        executor.execute(new Runnable() {
            public void run() {
                // 任务执行的代码
                System.out.println("任务正在执行……");
            }
        });
        executor.shutdown();
    }
}
