/**-----------------------------------------------
  * @Copyright (C) 2018 All rights reserved.
  * @file: scheduler.c
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @created_date: 2018-05-30 15:11:02
  * @last_modified_date: 2018-06-06 23:20:18
  * @brief: TODO
  *-----------------------------------------------*/

//INCLUDE
#include <scheduler.h>
#include <stdio.h>

//CODE
int init_task_manager(Task_MGR* mgr,
                       Task* task_array_ptr_will_set,
                       int maximum_task_will_set)
{
  mgr->task_list_ptr_ = task_array_ptr_will_set;
  mgr->maximum_tasks_ = maximum_task_will_set;
  mgr->number_of_tasks_ = 0;
  return SUCCESSED;
}

int monitor_task_manager(Task_MGR* mgr)
{
  printf("Maximum Task:  %d\n", mgr->maximum_tasks_);
  printf("The number of Tasks: %d\n", mgr->number_of_tasks_);
  printf("\n");
  printf("\n");
  return SUCCESSED;
}

int push_task(Task_MGR* mgr, Task* task_will_add)
{
  mgr->task_list_ptr_[mgr->number_of_tasks_] = *task_will_add;
  mgr->number_of_tasks_++;
  printf(" [DEBUG] Push a task SUCCESSFULLY\n");
  return SUCCESSED;
}

int add_task(Task_MGR* mgr,
              Task* task_will_add,
              int insert_position)
{
  if(insert_position > mgr->maximum_tasks_)
  {
    printf(" [DEBUG] The insert position proceeds the maxium tasks.\n");
    return FAILED;
  }
  else if(insert_position > mgr->number_of_tasks_)
  {
    printf(" [DEBUG] The insert position proceeds the number of current tasks.\n");
    push_task(mgr, task_will_add);
    return SUCCESSED;
  }
  else
  {
    int index = mgr->number_of_tasks_ - 1;
    while(index != insert_position)
    {
      mgr->task_list_ptr_[index] = mgr->task_list_ptr_[index - 1];
      index--;
    }
    mgr->task_list_ptr_[index] = *task_will_add;
    mgr->number_of_tasks_++;
    printf(" [DEBUG] Inserted!\n");
    return SUCCESSED;
  }
}
