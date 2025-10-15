import java.util.Arrays;

public class InterpolationSearch {

    /**
     * Рекурсивная реализация интерполирующего поиска.
     *
     * @param arr    Отсортированный массив.
     * @param target Искомое значение.
     * @param low    Нижняя граница поиска.
     * @param high   Верхняя граница поиска.
     * @return Индекс искомого элемента, если он найден, иначе -1.
     */
    public static int interpolationSearch(int[] arr, int target, int low, int high) {
        // Условие остановки: элемент не найден или границы неверны
        if (low <= high && target >= arr[low] && target <= arr[high]) {
            // Рассчитываем предполагаемую позицию (pos) элемента target
            // pos = low + [ (target - arr[low]) / (arr[high] - arr[low]) ] * (high - low)
            int pos = low + ((target - arr[low]) / (arr[high] - arr[low])) * (high - low);

            // Проверяем, найден ли элемент
            if (arr[pos] == target) {
                return pos;
            }

            // Если значение в pos больше искомого, искомый находится в левой части
            if (arr[pos] > target) {
                return interpolationSearch(arr, target, low, pos - 1);
            }
            // Если значение в pos меньше искомого, искомый находится в правой части
            else {
                return interpolationSearch(arr, target, pos + 1, high);
            }
        }

        // Элемент не найден
        return -1;
    }

    public static void main(String[] args) {
        int[] sortedArray = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
        int targetValue = 18;

        System.out.println("Ищем элемент " + targetValue + " в массиве: " + Arrays.toString(sortedArray));

        int resultIndex = interpolationSearch(sortedArray, targetValue, 0, sortedArray.length - 1);

        if (resultIndex != -1) {
            System.out.println("Элемент найден на позиции: " + resultIndex);
        } else {
            System.out.println("Элемент не найден");
        }
    }
}
