import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class newScheduledThreadPool {

    public static void main(String[] args) {

        // �����̶���С���̳߳�
        ScheduledExecutorService executor = Executors.newScheduledThreadPool(3);

        // ʹ�� scheduleAtFixedRate ���������̵߳���
        executor.scheduleAtFixedRate(() -> {
            System.out.println("ʹ�� scheduleAtFixedRate ���������̵߳��ȣ�ÿ 2 ��ִ��һ��");
        }, 0, 2, TimeUnit.SECONDS);

        // ʹ�� scheduleWithFixedDelay ���������̵߳���
        executor.scheduleWithFixedDelay(() -> {
            System.out.println("ʹ�� scheduleWithFixedDelay ���������̵߳��ȣ��ӳ� 2 ��ִ��");
        }, 0, 2, TimeUnit.SECONDS);

        // �ر��̳߳�
        executor.shutdown();
    }

}
