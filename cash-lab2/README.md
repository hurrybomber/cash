# Лабораторная работа #2

> Кэш - промежуточный буфер с быстрым доступом, содержащий информацию, которая может быть запрошена с наибольшей вероятностью. Доступ к данным в кэше осуществляется быстрее, чем выборка исходных данных из более медленной памяти или удаленного источника, однако её объём существенно ограничен по сравнению с хранилищем исходных данных.

### Задача

Для каждого из вариантов проходов (*прямой*, *обратный* и *случайный*) целочисленного массива 
провести исследование зависимости времени от размера.

Каждое исследование включает в себя серию эксперементов c определенными размерами.

Количество экспериментов в серии определяется следующим образом:

```cpp
1/2 * cache_sizes['1'] < 2^x < 2^(x+1) < ... < 2^(x+n) < 3/2 * cache_sizes['max']
```

### Пример

В примере ниже показано, что для процессора с тремя уровнями кэша (`2mb`, `4mb`, `8mb`)
необходимо провести серию из 5 эксперементов.

```cpp
cache_size['1'] = 2 mb;
cache_size['2'] = 4 mb;
cache_size['3'] = 8 mb;

// 1mb < 2mb < 4mb < 8mb < 12mb
```

### Эксперимент

Каждый эксперемент состоит из 3 шагов:

```cpp
1. Создание буфера
2. Прогревание кэша
// <-- время начала эксперемнта
3. Циклический проход (1000 итераций)
// <-- время окончание эксперемента
```

#### Шаг 1

Инициализация буфера может происходит, как с помощью чтения данных из файла в выделенную область памяти,
так и с помощью случайного заполнения с использованием генератора случайных чисел.

#### Шаг 2

Данный шаг необходимо выполнить для получения репрезентативных данных, т.к. кэш-память еще не заполнена.

#### Шаг 3

Для получения времени обхода от размера массива процедуру прохода необходимо многократно повторить (порядка 1000 раз).

### Результаты

Ниже представлен отчет:

```yaml
investigation:                                       
  travel_variant: <direct>                 
  experiments:                                     
  - experiment:                                     
      number: 1                                       
      input_data:                                  
        buffer_size: <128КБ>                
      results:                                     
        duration: <672047>              
  - experiment:                                     
      number: 2                                       
      input_data:                                  
        buffer_size: <256КБ>                
      results:                                     
        duration: <1338404>      
  - experiment:                                     
      number: 3                                       
      input_data:                                  
        buffer_size: <512КБ>                
      results:                                     
        duration: <2638719>              
       
   - experiment:                                     
      number: 4                                       
      input_data:                                  
        buffer_size: <1МБ>                
      results:                                     
        duration: <5394452>              
  - experiment:                                     
      number: 5                                       
      input_data:                                  
        buffer_size: <2МБ>                
      results:                                     
        duration: <10667098>              
  - experiment:                                     
      number: 6                                       
      input_data:                                  
        buffer_size: <4МБ>                
      results:                                     
        duration: <21047749>              
  - experiment:                                     
      number: 7                                      
      input_data:                                  
        buffer_size: <8МБ>                
      results:                                     
        duration: <42038097>              
                                                    
                                       
  travel_variant: <reverse>                 
  experiments:                                     
  - experiment:                                     
      number: 1                                       
      input_data:                                  
        buffer_size: <128КБ>                
      results:                                     
        duration: <646185>              
  - experiment:                                     
      number: 2                                       
      input_data:                                  
        buffer_size: <256КБ>                
      results:                                     
        duration: <1292774>      
  - experiment:                                     
      number: 3                                       
      input_data:                                  
        buffer_size: <512КБ>                
      results:                                     
        duration: <2607085>              
       
   - experiment:                                     
      number: 4                                       
      input_data:                                  
        buffer_size: <1МБ>                
      results:                                     
        duration: <5233985>              
  - experiment:                                     
      number: 5                                       
      input_data:                                  
        buffer_size: <2МБ>                
      results:                                     
        duration: <10465642>              
  - experiment:                                     
      number: 6                                       
      input_data:                                  
        buffer_size: <4МБ>                
      results:                                     
        duration: <20877982>              
  - experiment:                                     
      number: 7                                      
      input_data:                                  
        buffer_size: <8МБ>                
      results:                                     
        duration: <41792545>              
                     
                                       
  travel_variant: <random>                 
  experiments:                                     
  - experiment:                                     
      number: 1                                       
      input_data:                                  
        buffer_size: <128КБ>                
      results:                                     
        duration: <1802512>              
  - experiment:                                     
      number: 2                                       
      input_data:                                  
        buffer_size: <256КБ>                
      results:                                     
        duration: <3691615>      
  - experiment:                                     
      number: 3                                       
      input_data:                                  
        buffer_size: <512КБ>                
      results:                                     
        duration: <7492720>              
       
   - experiment:                                     
      number: 4                                       
      input_data:                                  
        buffer_size: <1МБ>                
      results:                                     
        duration: <15437147>              
  - experiment:                                     
      number: 5                                       
      input_data:                                  
        buffer_size: <2МБ>                
      results:                                     
        duration: <32509466>              
  - experiment:                                     
      number: 6                                       
      input_data:                                  
        buffer_size: <4МБ>                
      results:                                     
        duration: <66881827>              
  - experiment:                                     
      number: 7                                      
      input_data:                                  
        buffer_size: <8МБ>                
      results:                                     
        duration: <151297540>              
                                                      
```

![graph](/graph/2.png)
