/*!********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  my_application_module_base.h
 *         \brief
 *
 *********************************************************************************************************************/

#ifndef APPS_MY_APPLICATION_MODULE_BASE_H
#define APPS_MY_APPLICATION_MODULE_BASE_H

#include <memory>
#include "vaf/controller_interface.h"

#include "test/my_interface_consumer.h"
#include "test/my_interface_provider.h"

namespace apps {

class MyApplicationModuleBase {
 public:
  struct ConstructorToken {
    std::shared_ptr<test::MyInterfaceConsumer> c_interface_instance_1_;
    std::shared_ptr<test::MyInterfaceConsumer> c_interface_instance_2_;
    std::shared_ptr<test::MyInterfaceProvider> p_interface_instance_1_;
    std::shared_ptr<test::MyInterfaceProvider> p_interface_instance_2_;
  };

  MyApplicationModuleBase(ConstructorToken&& token);
  virtual ~MyApplicationModuleBase() = default;

  void ReportError(vaf::ErrorCode, std::string, bool) {}
  virtual void OnError(const vaf::Error&) {}
  std::string GetName() { return ""; }

  virtual void task1() = 0;
  virtual void task2() = 0;

 protected:
  std::shared_ptr<test::MyInterfaceConsumer> c_interface_instance_1_;
  std::shared_ptr<test::MyInterfaceConsumer> c_interface_instance_2_;
  std::shared_ptr<test::MyInterfaceProvider> p_interface_instance_1_;
  std::shared_ptr<test::MyInterfaceProvider> p_interface_instance_2_;
};

} // namespace apps

#endif // APPS_MY_APPLICATION_MODULE_BASE_H
