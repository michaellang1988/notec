use pyo3::prelude::*;
use std::collections::HashMap;

// #[pyclass]
// #[derive(Clone)]
// pub struct BasePulse {
//     fake: bool,
//     pulse_type: String,
//     pulse_time: f64,

// }

// #[pymethods]
// impl BasePulse {
//     #[new]
//     fn new() -> Self {
//         BasePulse {
//             fake: false,
//             pulse_time: 0.0,
//             pulse_type: String::from("x"),
//             // time: 10.1,
//         }
//     }

//     fn pulse(&self) -> PyResult<Self>{
//         Ok(self.clone())
//     }
// }

struct PulseStruct {
    fake: bool,
    parameters: HashMap<String, PyAny>,
}
trait PulseOperation {
    fn __add__(&self, other: PulseStruct) -> PulseStruct;
}


