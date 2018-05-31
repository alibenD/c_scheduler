/**-----------------------------------------------
  * @Copyright (C) 2018 All rights reserved.
  * @file: test_scheduler.c
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @created_date: 2018-05-30 20:15:28
  * @last_modified_date: 2018-05-31 17:29:56
  * @brief: TODO
  *-----------------------------------------------*/

//INCLUDE
#include <scheduler.h>
#include <stdio.h>

//CODE
int main(int argc, char** argv)
{
  printf("Test!\n");
  const int MAX_NUMBER_TASKS = 10;
  Task task_list[MAX_NUMBER_TASKS];
  Task_MGR task_mgr;
  init_task_manager(&task_mgr, task_list, MAX_NUMBER_TASKS);

  Task task1;
  Task task2;

  monitor_task_manager(&task_mgr);

  add_new_task(&task_mgr, &task1);
  monitor_task_manager(&task_mgr);
  add_new_task(&task_mgr, &task2);
  monitor_task_manager(&task_mgr);
  return 0;
}
