#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__
/**-----------------------------------------------
  * @Copyright (C) 2018 All rights reserved.
  * @date: 2018
  * @author: aliben.develop@gmail.com
  * @brief: TODO
  * @version: v0.0.1
  * @file: scheduler.h
  * @create_date: 2018-05-30 15:11:02
  * @last_modified_date: 2018-05-31 17:38:06
  *-----------------------------------------------*/

// INCLUDE
#ifndef INF
#define INF -1
#endif

typedef unsigned char flag_t;

struct Task_Element
{
  int (*task_ptr)(void* p_ptr);
  int task_id_;
  flag_t is_delay_;
  flag_t is_repeat_;
  flag_t is_runnning_;

  int sec_delay_;
  int repeat_period_;
  //int count_run;
};

typedef struct Task_Element Task;

struct Task_Mangager
{
  Task* task_list_ptr_;
  int maximum_tasks_;
  int number_of_tasks_;
};

typedef struct Task_Mangager Task_MGR;

void init_task_manager(Task_MGR* mgr,
                       Task* task_array_ptr,
                       int number_of_task);
void add_new_task(Task_MGR* mgr,
                  Task* task_will_add);

void monitor_task_manager(Task_MGR* mgr);
// DECLARATION

#endif // __SCHEDULER_H__
