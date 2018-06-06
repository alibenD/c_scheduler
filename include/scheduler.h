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
  * @last_modified_date: 2018-06-06 22:27:21
  *-----------------------------------------------*/

// INCLUDE
#ifndef INF
#define INF -1
#endif

#ifndef FAILED
#define FAILED -1
#endif

#ifndef SUCCESSED
#define SUCCESSED -1
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

int init_task_manager(Task_MGR* mgr,
                       Task* task_array_ptr,
                       int number_of_task);
int push_task(Task_MGR* mgr,
               Task* task_will_add);
int add_task(Task_MGR* mgr,
              Task* task_will_add,
              int insert_position);

int monitor_task_manager(Task_MGR* mgr);
// DECLARATION

#endif // __SCHEDULER_H__
