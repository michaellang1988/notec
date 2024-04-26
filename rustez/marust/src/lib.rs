use pyo3::prelude::*;
/// Formats the sum of two numbers as string.
#[pyfunction]
fn sum_as_string(a: usize, b: usize) -> PyResult<String> {
    Ok((a * b).to_string())
}

#[pyclass]
#[derive(Clone)]
struct SimplePulse {
    // _pulse_type: String,
    time11: f64,
    delay: f64,
    // _sweep: String,
    // _width: f64,
    // _bit: String,
    _fake_pulse: bool,
}
#[pymethods]
impl SimplePulse {
    fn test(&self) -> f64 {
        self.time11 * self.delay
    }
    #[new]
    fn new(t_: f64, d_: f64) -> Self{
        SimplePulse{
            time11: t_,
            delay: d_,
            _fake_pulse: true,
        }
    }

    #[getter]
    fn time(&self) -> f64{
        self.time11
    }

    fn __str__(&self) -> String{
       format!( "SimplePulse:{} {}", self.delay, self.time11)
    }

    fn __add__(&mut self, other: &mut SimplePulse) ->PyResult<Self> {

        self.delay = self.delay + other.delay;
        self.time11 = self.time11 * other.time11;
        Ok(self.clone())
    }

}

/// A Python module implemented in Rust.
#[pymodule]
fn marust(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_function(wrap_pyfunction!(sum_as_string, m)?)?;
    m.add_class::<SimplePulse>()?;
    Ok(())
}
