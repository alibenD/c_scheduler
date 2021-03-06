/**-----------------------------------------------
  * @Copyright (C) 2018 All rights reserved.
  * @file: scheduler.c
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @created_date: 2018-05-30 15:11:02
  * @last_modified_date: 2018-06-10 00:41:54
  * @brief: TODO
  *-----------------------------------------------*/

//INCLUDE
#include <scheduler.h>
#ifdef DEBUG_MODE
#include <stdio.h>
#endif
#include <unistd.h>

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
#ifdef DEBUG_MODE
  //printf("Maximum Task:  %d\n", mgr->maximum_tasks_);
  printf("The number of Tasks: %d\n", mgr->number_of_tasks_);
  printf("\n");
  printf("\n");
#endif
  return SUCCESSED;
}

int push_task(Task_MGR* mgr, Task* task_will_add)
{
  mgr->task_list_ptr_[mgr->number_of_tasks_] = *task_will_add;
  mgr->number_of_tasks_++;
  #ifdef DEBUG_MODE
    printf(" [DEBUG] Push a task SUCCESSFULLY\n");
  #endif
  return SUCCESSED;
}

int add_task(Task_MGR* mgr,
              Task* task_will_add,
              int insert_position)
{
  if(insert_position > mgr->maximum_tasks_)
  {
    #ifdef DEBUG_MODE
      printf(" [DEBUG] The insert position proceeds the maxium tasks.\n");
    #endif
    return FAILED;
  }
  else if(insert_position > mgr->number_of_tasks_)
  {
    #ifdef DEBUG_MODE
      printf(" [DEBUG] The insert position proceeds the number of current tasks.\n");
    #endif
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
    #ifdef DEBUG_MODE
      printf(" [DEBUG] Inserted!\n");
    #endif
    return SUCCESSED;
  }
}

int pop_task(Task_MGR* mgr)
{
  if(mgr->number_of_tasks_ < 1)
  {
    #ifdef DEBUG_MODE
      printf(" [DEBUG] Task list is empty.\n");
    #endif
    return FAILED;
  }
  //mgr->task_list_ptr_[mgr->number_of_tasks_] = NULL;
  mgr->number_of_tasks_--;
  #ifdef DEBUG_MODE
    printf(" [DEBUG] Popped task.\n");
  #endif
  return SUCCESSED;
}

int delete_task(Task_MGR* mgr,
                int index)
{
  if(index > mgr->maximum_tasks_)
  {
    #ifdef DEBUG_MODE
      printf(" [DEBUG] Index exceeds the boundary.\n");
    #endif
    return FAILED;
  }
  else if(index > mgr->number_of_tasks_)
  {
    #ifdef DEBUG_MODE
      printf(" [DEBUG] Index exceeds the number of existing tasks.\n");
    #endif
    return FAILED;
  }
  else
  {
    int t_index = index - 1;
    while(t_index + 1 < mgr->number_of_tasks_)
    {
      mgr->task_list_ptr_[t_index] = mgr->task_list_ptr_[t_index + 1];
      t_index++;
    }
    mgr->number_of_tasks_--;
    #ifdef DEBUG_MODE
      printf(" [DEBUG] Task%d has been deleted.\n", index);
    #endif
    return SUCCESSED;
  }
}

int dispatch_task(Task_MGR* mgr)
{
  int index = 0;
  int void_ptr = 0;
  while(index < mgr->number_of_tasks_)
  {
    if(mgr->task_list_ptr_[index].is_running_ != 0)
    {
      #ifdef DEBUG_MODE
        printf(" [DEBUG] Task_id->%d will run\n", mgr->task_list_ptr_[index].task_id_);
      #endif
      mgr->task_list_ptr_[index].task_ptr((void*)&void_ptr);
      mgr->task_list_ptr_[index].is_running_ = 0;
      if(mgr->task_list_ptr_[index].is_repeat_ == 0)
      {
        delete_task(mgr, index+1);
        continue;
      }
    }
    index++;
  }
  return 0;
}

void scheduler_update(void* mgr_ptr)
{
  Task_MGR* mgr = (Task_MGR*)mgr_ptr;
  int index = 0;
  #ifdef DEBUG_MODE
    printf("[DEBUG] In thread\n");
  #endif
  #ifdef X86
  while(1){
  #endif
  while(index < mgr->number_of_tasks_)
  {
  //#ifdef DEBUG_MODE
  //  //printf(" [DEBUG] In thread\n");
  //  printf(" [DEBUG] In thread: task%d\n", index + 1);
  //#endif
    if(mgr->task_list_ptr_[index].msec_delay_ == 0)
    {
      mgr->task_list_ptr_[index].is_running_ = 1;
      if(mgr->task_list_ptr_[index].is_repeat_ == 1)
      {
        mgr->task_list_ptr_[index].msec_delay_ = mgr->task_list_ptr_[index].repeat_period_;
      }
    }
    else
    {
      mgr->task_list_ptr_[index].msec_delay_--;
    }
    index++;
  }
  #ifdef X86
  index = 0;
  sleep(1);
  }
  #endif
}
