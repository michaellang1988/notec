use pyo3::prelude::*;
use std::collections::HashMap;

#[pyclass]
pub struct PulseComponent {
    #[pyo3(get, set)]
    time: f64,
    #[pyo3(get, set)]
    type_: String,
    #[pyo3(get, set)]
    _pulse: Option<Vec<i32>>,  // pulse sequence
    #[pyo3(get, set)]
    _raw_pulse: Option<Vec<i32>>,  // pulse sequence without any correction
    #[pyo3(get, set)]
    _envelope: Option<Vec<i32>>,  // pulse envelope
    #[pyo3(get, set)]
    _attach: bool,
    #[pyo3(get, set)]
    _delay: i32,
    #[pyo3(get, set)]
    _bit: String,
    #[pyo3(get, set)]
    _sweep: String,
    #[pyo3(get)]
    _width: f64,
    #[pyo3(get)]
    _lost_width: f64,
    #[pyo3(get)]
    _pulse_repr: String,
    #[pyo3(get, set)]
    correction: Option<Vec<i32>>,
    #[pyo3(get, set)]
    multiple_freq: Vec<i32>,
    #[pyo3(get, set)]
    envelope_fragment: Vec<i32>,
    #[pyo3(get, set)]
    _pulse_complexes: Vec<i32>,
    #[pyo3(get, set)]
    extra_bias: i32,
    #[pyo3(get, set)]
    base: i32,
    #[pyo3(get, set)]
    _fake_pulse: Option<Vec<i32>>,
    #[pyo3(get, set)]
    _parameters: HashMap<String, i32>,
}

#[pymethods]
impl PulseComponent {
    #[new]
    fn new(time: f64, type_: String) -> Self {
        let width = time.round();
        let lost_width = width;
        let pulse_repr = format!("{}(time={})", stringify!($self.__class__.__name__), width);
        
        PulseComponent {
            time,
            type_,
            _pulse: None,
            _raw_pulse: None,
            _envelope: None,
            _attach: false,
            _delay: 0,
            _bit: String::new(),
            _sweep: String::new(),
            _width: width,
            _lost_width: lost_width,
            _pulse_repr: pulse_repr,
            correction: None,
            multiple_freq: Vec::new(),
            envelope_fragment: Vec::new(),
            _pulse_complexes: Vec::new(),
            extra_bias: 0,
            base: 0,
            _fake_pulse: None,
            _parameters: HashMap::new(),
        }
    }

    fn pulse(&self, ) -> PyResult<f64> {
        Ok(self.time)
    }
}
