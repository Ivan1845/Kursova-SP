#!/bin/bash

# Генерація 5 випадкових додатних чисел
numbers=()
for i in {1..5}; do
    numbers+=($((RANDOM % 100 + 1)))  # Генерація чисел від 1 до 100
done

# Виведення згенерованих чисел на екран
echo "Згенеровані числа:"
for num in "${numbers[@]}"; do
    echo "$num"
done

# Запис чисел у файл
file="numbers.txt"
echo "${numbers[@]}" > "$file"
echo "Числа записані у файл $file."

# Збереження лише найменшого числа в файлі
min_number=$(echo "${numbers[@]}" | tr ' ' '\n' | sort -n | head -n 1)
echo "$min_number" > "$file"  # Записуємо лише найменше число

# Виведення результату на екран
echo "Найменше число: $min_number"
echo "Файл після збереження найменшого числа:"
cat "$file"
