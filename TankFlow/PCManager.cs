using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace TankFlow
{
    class PCManager
    {
        private Object[] resources;
        private int in_index;
        private int out_index;
        private Semaphore rest_resource;
        private Semaphore used_resource;
        private Mutex in_mutex;
        private Mutex out_mutex;

        private int resource_sum;

        public PCManager(int resource_sum)
        {
            this.resource_sum = resource_sum;
            init(resource_sum);
        }

        private void init(int resource_sum)
        {
            in_index = 0;
            out_index = 0;
            resources = new object[resource_sum];

            rest_resource = new Semaphore(resource_sum, resource_sum);
            used_resource = new Semaphore(0, resource_sum);
            in_mutex = new Mutex();
            out_mutex = new Mutex();
        }

        public Object GetProduct()
        {
            Object result;
            used_resource.WaitOne();
            out_mutex.WaitOne();

            result = resources[out_index];
            out_index = (out_index + 1) % resource_sum;

            out_mutex.ReleaseMutex();
            rest_resource.Release(1);
            return result;
        }

        //使用当前线程添加一个产品
        public void AddProduct(object m)
        {
            rest_resource.WaitOne();
            in_mutex.WaitOne();

            resources[in_index] = m;
            in_index = (in_index + 1) % resource_sum;

            in_mutex.ReleaseMutex();
            used_resource.Release(1);
        }

        //使用新线程添加一个产品
        public void AddProductPlus(object m)
        {
            Thread th = new Thread(() =>
            {
                AddProduct(m);
            });
            th.Start();
        }

    }


}
