import java.util.Arrays;

public class SelectionSort {

    public static void selectionSort(int[] arr) {
        int n = arr.length;

        // Проходим по всем элементам массива
        for (int i = 0; i < n - 1; i++) {
            // Предполагаем, что первый элемент в неотсортированной части - минимальный
            int minIndex = i;

            // Ищем минимальный элемент в оставшейся части массива
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // Меняем найденный минимальный элемент с первым элементом в неотсортированной части
            if (minIndex != i) { // Оптимизация: не меняем местами, если элемент уже на своём месте
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] testArray = {64, 25, 12, 22, 11};

        System.out.println("Исходный массив: " + Arrays.toString(testArray));

        selectionSort(testArray);

        System.out.println("Отсортированный массив: " + Arrays.toString(testArray));
    }
}
