/**-----------------------------------------------
  * @Copyright (C) 2018 All rights reserved.
  * @file: scheduler.c
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @created_date: 2018-05-30 15:11:02
  * @last_modified_date: 2018-05-30 21:21:02
  * @brief: TODO
  *-----------------------------------------------*/

//INCLUDE
#include <scheduler.h>
#include <stdio.h>

//CODE
void init_task_manager(task_mgr* mgr,
                  Task* task_array_ptr_will_set,
                  int maximum_task_will_set)
{
  mgr->task_list_ptr_ = task_array_ptr_will_set;
  mgr->index_task_ = 0;
  mgr->maximum_tasks_ = maximum_task_will_set;
  mgr->number_of_tasks_ = 0;
}

void monitor_task_manager(task_mgr* mgr)
{
  printf("Maximum Task:  %d\n", mgr->maximum_tasks_);
  printf("Current Task#: %d\n", mgr->number_of_tasks_);
  printf("\n");
  printf("\n");
}
