#include <iostream>
#include <cstdlib>
using namespace std;

void quick_sort(int* num, int left, int right) {
  if (left >= right) return;

  int pivot = num[left];
  int origin_left = left;
  int origin_right = right;

  while (left < right) {
    // Find the first element smaller than pivot.
    while (left < right && num[right] >= pivot)
      right--;

    if (left < right) {
      num[left] = num[right];
      left++;
    }

    // Find the first element larger that pivot.
    while (left < right && num[left] <= pivot)
      left++;

    if (left < right) {
      num[right] = num[left];
      right--;
    }
  }

  num[left] = pivot;
  quick_sort(num, origin_left, left - 1);
  quick_sort(num, left + 1, origin_right);
}

int main() {
  const int length = 20;
  int num[length];

  for (int i = 0; i < length; ++i)
    num[i] = rand() % 100;

  quick_sort(num, 0, length - 1);

  for (int i = 0; i < length; ++i)
    cout << num[i] << " ";

  cout << endl;

  return 0;
}
