/**-----------------------------------------------
  * @Copyright (C) 2018 All rights reserved.
  * @file: test_scheduler.c
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @created_date: 2018-05-30 20:15:28
  * @last_modified_date: 2018-05-31 14:18:41
  * @brief: TODO
  *-----------------------------------------------*/

//INCLUDE
#include <scheduler.h>
#include <stdio.h>

//CODE
int main(int argc, char** argv)
{
  printf("Test!\n");
  Task_MGR task_mgr;
  monitor_task_manager(&task_mgr);
  return 0;
}
