

public class createThread_Main {

    public static void main(String[] args) throws Exception {
        // ʵ�����߳�������
        createThread_Task task = new createThread_Task();

        // �����̶߳���,�����߳���������Ϊ���췽����������
        new Thread(task).start();

        // ���̵߳�����Ϊ����ʾ����߳�һ��ִ��
        while (true) {
            printThreadInfo();
            Thread.sleep(1000);
        }
    }

    /**
     * �����ǰ�̵߳���Ϣ
     */
    private static void printThreadInfo() {
        System.out.println("��ǰ���е��߳���Ϊ�� " + Thread.currentThread().getName());
    }
}
