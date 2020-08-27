#ifdef PYBIND_BUILD
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <pybind11/functional.h>

#include "dependencies/x52/x52/stdafx.h"
#include "dependencies/x52/x52/X52.h"

namespace py = pybind11;

PYBIND11_MODULE(_x52, m) {

    m.doc() = "rafls fun lib";

    py::class_<X52Page>(m, "X52Page")
        .def(py::init<>())
        .def(py::init<bool>())
        .def(py::init<std::tuple<std::string, std::function<void()>>, std::tuple<std::string, std::function<void()>>, std::tuple<std::string, std::function<void()>>>())
        .def(py::init<std::tuple<std::string, std::function<void()>>, std::tuple<std::string, std::function<void()>>, std::tuple<std::string, std::function<void()>>, bool>())
        .def("get_text_top", &X52Page::get_text_top)
        .def("get_text_mid", &X52Page::get_text_mid)
        .def("get_text_bot", &X52Page::get_text_bot)
        .def("set_text_top", &X52Page::set_text_top)
        .def("set_text_mid", &X52Page::set_text_mid)
        .def("set_text_bot", &X52Page::set_text_bot)
        .def("is_interactive", &X52Page::is_interactive)
        .def(py::self == py::self)
    ;

    py::class_<X52Device>(m, "X52Device")
        .def(py::init<void*, void*>())
        .def("page_add", &X52Device::page_add)
        .def("drawPage", &X52Device::drawPage)
        ;

    py::class_<X52>(m, "X52")
        .def(py::init<>())
        .def("init", &X52::init)
        .def("device_get", &X52::device_get)
        .def("get_x52devices", &X52::get_x52devices)
    ;

    py::module utils = m.def_submodule("utils", "Utility functions");
    utils.def("current_time_millis", &current_time_millis, "Returns the passed millis since epoch");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
#endif // PYBIND_BILD