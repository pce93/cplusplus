using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project3
{
    class Program
    {
        static void Main()
        {
            /*Stack stk = new Stack(1);
            if (stk.Size() == 0)
                Console.WriteLine("You good");
            if (stk.Empty() == true) 
                Console.WriteLine("You good");
            stk.Push(28.9);
           
            stk.Push(52.3);
            stk.Push(52.3);
            stk.Pop();
            stk.Pop();
            stk.Pop();
            if (stk.Size() == 0)
                Console.WriteLine("You good");
            if (stk.Empty() == true)
                Console.WriteLine("You good");*/

            // allocating only space for one item, to test resizing
            Stack stk = new Stack(1);

            // empty case
            Debug.Assert(stk.Size() == 0);
            Debug.Assert(stk.Empty() == true);

            // add some items
            stk.Push(28.9);
            // should resize here!
            stk.Push(52.3);

            // test!
            Debug.Assert(stk.Size() == 2);
            Debug.Assert(stk.Empty() == false);

            double check = stk.Pop();
            Debug.Assert(stk.Size() == 1);
            Debug.Assert(check == 52.3);

            stk.Push(-77.8);

            check = stk.Pop();
            Debug.Assert(stk.Size() == 1);
            Debug.Assert(check == -77.8);

            check = stk.Pop();
            Debug.Assert(stk.Size() == 0);
            Debug.Assert(check == 28.9);



        }
        class Stack
        {
            private double[] stack;
            private int count;
            private int size;
            public Stack(int n)
            {
                stack = new double[n];
                count = 0;
                size = n;
            }

            public bool Empty()
            {
                if (count == 0)
                {
                    return true;
                }
                else
                    return false;
            }

            public int Size()
            {
                return count;
            }

            public void Push(double element)
            {
                if (count == size)
                {
                    Resize();
                }
                stack[count] = element;
                count++;
            }

            public double Pop()
            {
                if (count == 0)
                {
                    return 0;
                }
                double n = stack[count - 1];
                stack[count - 1] = 0;
                count--;
                return n;
            }

            private void Resize()
            {
                Array.Resize(ref stack, size * 2);
                size = size * 2;
            }
        }
    }
}
