import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class newScheduledThreadPool {

    public static void main(String[] args) {

        // 创建固定大小的线程池
        ScheduledExecutorService executor = Executors.newScheduledThreadPool(3);

        // 使用 scheduleAtFixedRate 方法进行线程调度
        executor.scheduleAtFixedRate(() -> {
            System.out.println("使用 scheduleAtFixedRate 方法进行线程调度，每 2 秒执行一次");
        }, 0, 2, TimeUnit.SECONDS);

        // 使用 scheduleWithFixedDelay 方法进行线程调度
        executor.scheduleWithFixedDelay(() -> {
            System.out.println("使用 scheduleWithFixedDelay 方法进行线程调度，延迟 2 秒执行");
        }, 0, 2, TimeUnit.SECONDS);

        // 关闭线程池
        executor.shutdown();
    }

}
