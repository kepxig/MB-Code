// ������ؿ�
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class Main {
public static void main(String[] args) {

    // ����һ���̲߳���ȫ�� HashMap
    Map<String, String> hashMap = new HashMap<>();

    // �� hashMap ���������
    hashMap.put("apple", "red");
    hashMap.put("banana", "yellow");
    hashMap.put("kiwi", "green");

    // ʹ�� Collections.synchronizedMap(Map<K,V> m) ��װ hashMap
    Map<String, String> synchronizedMap = Collections.synchronizedMap(hashMap);

    // ����һ���̰߳�ȫ�� ConcurrentHashMap
    ConcurrentHashMap<String, String> concurrentHashMap = new ConcurrentHashMap<>();

    // �� concurrentHashMap ���������
    concurrentHashMap.put("apple", "red");
    concurrentHashMap.put("banana", "yellow");
    concurrentHashMap.put("kiwi", "green");

    // ��� ConcurrentHashMap �Ĵ�С
    System.out.println("ConcurrentHashMap size: " + concurrentHashMap.size());
}
}