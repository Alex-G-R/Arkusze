using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void ByteRunCompress(char[] a, int length)
        {
            int i = 0;

            while (i < length)
            {
                if((i < length-1) && (a[i] == a[i+1]))
                {
                    int j = 0;
                    while((i+j < length - 1) && (a[i+j] == a[i+j+1]) && (j < 127))
                    {
                        j++;
                    }
                    Console.Write(-j);
                    Console.Write(", ");
                    Console.Write(a[i+j]);
                    Console.Write(", ");
                    i += (j + 1);
                }
                else
                {
                    int j = 0;
                    while((i+j < length - 1) && (a[i+j] !=a[j+i+1]) && (j < 128))
                    {
                        j++;
                    }
                    if((i+j == length-1) && (j<128))
                    {
                        j++;
                    }
                    Console.Write(j-1);
                    Console.Write(", ");
                    for(int k = 0; k < j; k++)
                    {
                        Console.Write(a[i+k]);
                        Console.Write(", ");
                    }
                    i += j;
                }
            }
        }

        static void Main(string[] args)
        {
            char[] to_compress = { 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'G', 'B', 'B', 'K' };
            ByteRunCompress(to_compress, to_compress.Length);
            Console.WriteLine("\n");

            Console.ReadLine();
        }
    }
}
