package mergesort;
import java.util.Arrays;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

public class ParallelMergeSort extends RecursiveAction {
    private final int[] array;
    private final int low;
    private final int high;

    public ParallelMergeSort(int[] array, int low, int high) {
        this.array = array;
        this.low = low;
        this.high = high;
    }

    protected void compute() {
        if (low < high) {
            if (high - low <= 1000) {
                // ��С����ʹ�ô��й鲢����
                Arrays.sort(array, low, high);
            } else {
                int mid = low + (high - low) / 2;
                // ��������Ϊ������������ִ��
                invokeAll(new ParallelMergeSort(array, low, mid), new ParallelMergeSort(array, mid, high));
                // �ϲ�������������
                merge(array, low, mid, high);
            }
        }
    }

    private void merge(int[] array, int low, int mid, int high) {
        int[] left = Arrays.copyOfRange(array, low, mid);
        int[] right = Arrays.copyOfRange(array, mid, high);
        int i = 0, j = 0, k = low;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }
        while (i < left.length) {
            array[k++] = left[i++];
        }
        while (j < right.length) {
            array[k++] = right[j++];
        }
    }

    public static void main(String[] args) {
        int[] array = {9, 7, 5, 11, 12, 2, 14, 3, 6, 1, 8, 10, 4};
        
        System.out.println("Original Array: " + Arrays.toString(array));
        
        // ���� ForkJoinPool ����
        ForkJoinPool forkJoinPool = new ForkJoinPool();
        
        // �������й鲢��������
        ParallelMergeSort mergeSort = new ParallelMergeSort(array, 0, array.length);
        
        // ִ������
        forkJoinPool.invoke(mergeSort);
        
        // ��ӡ������
        System.out.println("Sorted Array: " + Arrays.toString(array));
    }
}