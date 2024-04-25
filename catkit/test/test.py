from catkit.example_interface import calculate_sum
import msgpack
import json
import time
from catkit.msgpack_test import test

print(calculate_sum([1, 2, 3, 5, 534, 6, 7, 2]))


test_dict = {
    "FixedPointCalibration_for_qh": {
        "meta": {
            "username": "zyc",
            "visage_version": "0.4.7",
            "monster_version": "0.5.6.1",
            "chip": {
                "sample": "221205-72bit-300pin-V8.2P1-base-4#-72bitSE3",
                "env_name": "A2",
                "point_label": "batch_test",
            },
            "exp_class_name": "FixedPointCalibration",
            "export_datetime": "2023-12-22 17:41:32",
            "description": None,
        },
        "context_options": {
            "name": "cz_gate_calibration",
            "readout_type": "union-01-01",
            "physical_unit": "q1q2",
        },
        "options_for_regular_exec": {
            "experiment_options": {
                "child_exp_options": {
                    "delays": "Points(41) | qarange | (0, 200, 5)",
                    "fringe": 25,
                    "z_amp": None,
                    "frequency": None,
                    "ac_branch": None,
                    "tq_name": "qh",
                    "bq_name_list": "Points(0) | normal | ['qc']",
                    "bq_z_amp_list": "Points(0) | normal | [0.1]",
                },
                "z_amp": None,
                "frequency": None,
                "diff_frequency": None,
                "label": "zz",
                "gradient_type": "quadratic",
                "threshold": 0.1,
                "guess_step": 0.2,
                "iteration": 5,
                "trans_amp_to_freq": True,
            },
            "analysis_options": {
                "child_ana_options": {
                    "quality_bounds": [0.98, 0.93, 0.81],
                    "factor": 3.5,
                }
            },
        },
        "options_for_parallel_exec": {"experiment_options": {}, "analysis_options": {}},
    },
    "FixedPointCalibration_for_ql": {
        "meta": {
            "username": "zyc",
            "visage_version": "0.4.7",
            "monster_version": "0.5.6.1",
            "chip": {
                "sample": "221205-72bit-300pin-V8.2P1-base-4#-72bitSE3",
                "env_name": "A2",
                "point_label": "batch_test",
            },
            "exp_class_name": "FixedPointCalibration",
            "export_datetime": "2023-12-22 17:41:32",
            "description": None,
        },
        "context_options": {
            "name": "cz_gate_calibration",
            "readout_type": "union-01-01",
            "physical_unit": "q1q2",
        },
        "options_for_regular_exec": {
            "experiment_options": {
                "child_exp_options": {
                    "delays": "Points(41) | qarange | (0, 200, 5)",
                    "fringe": 25,
                    "z_amp": None,
                    "frequency": None,
                    "ac_branch": None,
                    "tq_name": "ql",
                    "bq_name_list": "Points(0) | normal | ['qc']",
                    "bq_z_amp_list": "Points(0) | normal | [0.1]",
                },
                "z_amp": None,
                "frequency": None,
                "diff_frequency": None,
                "label": "zz",
                "gradient_type": "quadratic",
                "threshold": 0.1,
                "guess_step": 0.2,
                "iteration": 5,
                "trans_amp_to_freq": True,
            },
            "analysis_options": {
                "child_ana_options": {
                    "quality_bounds": [0.98, 0.93, 0.81],
                    "factor": 3.5,
                }
            },
        },
        "options_for_parallel_exec": {"experiment_options": {}, "analysis_options": {}},
    },
    "FixedSwapFreqCaliCoupler": {
        "meta": {
            "username": "zyc",
            "visage_version": "0.4.7",
            "monster_version": "0.5.6.1",
            "chip": {
                "sample": "221205-72bit-300pin-V8.2P1-base-4#-72bitSE3",
                "env_name": "A2",
                "point_label": "batch_test",
            },
            "exp_class_name": "FixedSwapFreqCaliCoupler",
            "export_datetime": "2023-12-21 09:15:43",
            "description": None,
        },
        "context_options": {
            "name": "cz_gate_calibration",
            "readout_type": "ql-01",
            "physical_unit": "",
        },
        "options_for_regular_exec": {
            "experiment_options": {
                "child_exp_options": {
                    "swap_state": "11",
                    "scan_buffer": False,
                    "time_list": "Points(25) | qarange | (20.0, 80.0, 2.5)",
                    "label": "zz",
                },
                "z_amp": None,
                "frequency": None,
                "diff_frequency": None,
                "label": "zz",
                "gradient_type": "quadratic",
                "threshold": 0.1,
                "guess_step": 0.2,
                "iteration": 5,
                "cali_name": None,
                "trans_amp_to_freq": False,
            },
            "analysis_options": {
                "child_ana_options": {
                    "quality_bounds": [0.98, 0.95, 0.85],
                    "interaction_location": 1,
                    "data_key": "Points(0) | normal | None",
                    "fit_model_name": "swap_once_cosine",
                }
            },
        },
        "options_for_parallel_exec": {"experiment_options": {}, "analysis_options": {}},
    },
    "SwapOnce": {
        "meta": {
            "username": "zyc",
            "visage_version": "0.4.6",
            "monster_version": "0.5.6.1",
            "chip": {
                "sample": "221205-72bit-300pin-V8.2P1-base-4#-72bitSE3",
                "env_name": "A2",
                "point_label": "point_test",
            },
            "exp_class_name": "SwapOnce",
            "export_datetime": "2023-12-20 09:55:02",
            "description": None,
        },
        "context_options": {
            "name": "cz_gate_calibration",
            "readout_type": "ql-01",
            "physical_unit": "",
        },
        "options_for_regular_exec": {
            "experiment_options": {
                "swap_state": "01",
                "scan_buffer": False,
                "time_list": "Points(25) | qarange | (20.0, 80.0, 2.5)",
                "label": "zz",
                "is_dynamic": 0,
            },
            "analysis_options": {
                "quality_bounds": [0.98, 0.95, 0.85],
                "interaction_location": 1,
                "data_key": "Points(0) | normal | None",
                "fit_model_name": "swap_once_cosine",
            },
        },
        "options_for_parallel_exec": {"experiment_options": {}, "analysis_options": {}},
    },
    "ZZTimingComposite": {
        "meta": {
            "username": "zyc",
            "visage_version": "0.4.6",
            "monster_version": "0.5.6.1",
            "chip": {
                "sample": "221205-72bit-300pin-V8.2P1-base-4#-72bitSE3",
                "env_name": "A2",
                "point_label": "point_test",
            },
            "exp_class_name": "ZZTimingComposite",
            "export_datetime": "2023-12-20 09:55:02",
            "description": None,
        },
        "context_options": {
            "name": "cz_gate_calibration",
            "readout_type": "ql-01",
            "physical_unit": "",
        },
        "options_for_regular_exec": {
            "experiment_options": {
                "child_exp_options": {
                    "swap_state": "01",
                    "const_delay": {"ql": 20, "qh": 20, "qc": 20},
                    "delays": "Points(49) | qarange | (0.0, 39.984, 0.833)",
                    "scan_bit": "qc",
                    "z_pulse_params": {"sigma": None, "buffer": None},
                    "is_dynamic": 0,
                },
                "delay": 20,
                "iteration": 1,
                "mode": "All",
                "simulator_data_path": "D:\\project\\SupQAutomation\\code\\develop\\pyqcat-monster\\scripts\\simulator\\data\\ZZTimingComposite",
            },
            "analysis_options": {
                "child_ana_options": {
                    "extract_mode": "fit_params",
                    "fit_model_name": "gauss_lorentzian",
                    "filter": {"window_length": 5, "polyorder": 3},
                    "data_key": "Points(0) | normal | None",
                }
            },
        },
        "options_for_parallel_exec": {"experiment_options": {}, "analysis_options": {}},
    },
}


def use_time(use_func):

    def wrapper(*args, **kwargs):
        t1 = time.perf_counter()
        res = use_func(*args, **kwargs)
        t2 = time.perf_counter()
        print(f"{use_func.__name__} use time", t2 - t1)
        return res

    return wrapper


@use_time
def test_msgpack(data):
    return msgpack.dumps(data)


@use_time
def test_json(data):
    res = json.dumps(data)
    res = res.encode()
    return res


msg_bytes = test_msgpack(test_dict)
json_bytes = test_json(test_dict)

print(
    "msgpack data",
    len(msg_bytes),
    type(msg_bytes),
    "json data",
    len(json_bytes),
    type(json_bytes),
)


test()
