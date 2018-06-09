/**-----------------------------------------------
  * @Copyright (C) 2018 All rights reserved.
  * @file: test_dispatch.c
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @created_date: 2018-06-08 22:04:57
  * @last_modified_date: 2018-06-09 14:14:14
  * @brief: TODO
  *-----------------------------------------------*/

//INCLUDE
#include <scheduler.h>
#include <stdio.h>

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
  task1.is_running_ = 1;
  task1.is_repeat_ = 1;
  Task task2;
  task2.task_id_=2;
  task2.task_ptr=task2_test;
  task2.is_running_ = 1;
  task2.is_repeat_ = 0;
  Task task3;
  task3.task_id_=3;
  task3.task_ptr=task3_test;
  task3.is_running_ = 1;
  task3.is_repeat_ = 1;

  push_task(&task_mgr, &task1);
  push_task(&task_mgr, &task2);
  push_task(&task_mgr, &task3);

  #ifdef DEBUG_MODE
  monitor_task_manager(&task_mgr);
  #endif

  printf("Dispatch\n");
  dispatch_task(&task_mgr);
  return 0;
}
