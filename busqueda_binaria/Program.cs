using System;

namespace busqueda_binaria
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = { 1, 4, 50, 67, 80, 93, 123, 241 };
            int objective = 301;

            if (BinarySearch(array, objective, 0, array.Length - 1))
            {
                Console.WriteLine($"El elemento {objective} pertenece al Array");
            }
            else
            {
                Console.WriteLine($"El elemento {objective} NO pertenece al Array");
            }
        }

        static bool BinarySearch(int[] array, int objective, int left, int right)
        {
            while (left <= right)
            {
                int mid = left + (right - left) / 2;

                if (array[mid] == objective) 
                    return true;
                
                if (array[mid] < objective) 
                    left = mid + 1;
                else
                    right = mid - 1;

            }

            return false;
        }
        
    }

}
