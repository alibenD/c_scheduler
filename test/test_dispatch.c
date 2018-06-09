/**-----------------------------------------------
  * @Copyright (C) 2018 All rights reserved.
  * @file: test_dispatch.c
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @created_date: 2018-06-08 22:04:57
  * @last_modified_date: 2018-06-10 00:49:43
  * @brief: TODO
  *-----------------------------------------------*/

//INCLUDE
#include <scheduler.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int task1_test(void* p_ptr)
{
  printf("This is Task1\n");
  return 0;
}
int task2_test(void* p_ptr)
{
  printf("This is Task2\n");
  return 0;
}
int task3_test(void* p_ptr)
{
  printf("This is Task3\n");
  return 0;
}
int task4_test(void* p_ptr)
{
  printf("This is Task4\n");
  return 0;
}
int task5_test(void* p_ptr)
{
  printf("This is Task5\n");
  return 0;
}
int task6_test(void* p_ptr)
{
  printf("This is Task6\n");
  return 0;
}
int task7_test(void* p_ptr)
{
  printf("This is Task7\n");
  return 0;
}
int task8_test(void* p_ptr)
{
  printf("This is Task8\n");
  return 0;
}
//CODE
int main(int argc, char** argv)
{
  const int MAX_NUMBER_TASKS = 10;
  Task task_list[MAX_NUMBER_TASKS];
  Task_MGR task_mgr;
  init_task_manager(&task_mgr, task_list, MAX_NUMBER_TASKS);

  Task task1;
  task1.task_id_=1;
  task1.task_ptr=task1_test;
  task1.is_running_ = 0;
  task1.is_repeat_ = 1;
  task1.msec_delay_ = 0;
  task1.repeat_period_ = MAX_NUMBER_TASKS;

  Task task2;
  task2.task_id_=2;
  task2.task_ptr=task2_test;
  task2.is_running_ = 0;
  task2.is_repeat_ = 1;
  task2.msec_delay_ = 1;
  task2.repeat_period_ = MAX_NUMBER_TASKS;

  Task task3;
  task3.task_id_=3;
  task3.task_ptr=task3_test;
  task3.is_running_ = 0;
  task3.is_repeat_ = 1;
  task3.msec_delay_ = 2;
  task3.repeat_period_ = MAX_NUMBER_TASKS;

  Task task4;
  task4.task_id_=4;
  task4.task_ptr=task4_test;
  task4.is_running_ = 0;
  task4.is_repeat_ = 1;
  task4.msec_delay_ = 3;
  task4.repeat_period_ = MAX_NUMBER_TASKS;

  Task task5;
  task5.task_id_=5;
  task5.task_ptr=task5_test;
  task5.is_running_ = 0;
  task5.is_repeat_ = 1;
  task5.msec_delay_ = 4;
  task5.repeat_period_ = MAX_NUMBER_TASKS;

  Task task6;
  task6.task_id_=6;
  task6.task_ptr=task6_test;
  task6.is_running_ = 0;
  task6.is_repeat_ = 1;
  task6.msec_delay_ = 5;
  task6.repeat_period_ = MAX_NUMBER_TASKS;

  Task task7;
  task7.task_id_=7;
  task7.task_ptr=task7_test;
  task7.is_running_ = 0;
  task7.is_repeat_ = 1;
  task7.msec_delay_ = 6;
  task7.repeat_period_ = MAX_NUMBER_TASKS;

  Task task8;
  task8.task_id_=8;
  task8.task_ptr=task8_test;
  task8.is_running_ = 0;
  task8.is_repeat_ = 1;
  task8.msec_delay_ = 7;
  task8.repeat_period_ = MAX_NUMBER_TASKS;

  push_task(&task_mgr, &task1);
  push_task(&task_mgr, &task2);
  push_task(&task_mgr, &task3);
  push_task(&task_mgr, &task4);
  push_task(&task_mgr, &task5);
  push_task(&task_mgr, &task6);
  push_task(&task_mgr, &task7);
  push_task(&task_mgr, &task8);

  #ifdef DEBUG_MODE
  monitor_task_manager(&task_mgr);
  #endif

  pthread_t sch_update_thread;
  int pid = pthread_create(&sch_update_thread,
                           NULL,
                           (void*) scheduler_update,
                           (void*) &task_mgr);

  pthread_detach(sch_update_thread);
  printf("Dispatch\n");
  //dispatch_task(&task_mgr);
  while(1)
  {
    dispatch_task(&task_mgr);
    //sleep(1);
  }
  return 0;
}
