import os.path

import pytest

import config
from utils import get_shell_scripts


def get_test_cases():
    test_cases = []
    for script in get_shell_scripts("builtins/echo"):
        for method in config.METHODS:
            test_cases.append((script, method))
    return test_cases


def get_test_name(test_case):
    script, method = test_case
    script_name = os.path.basename(script.path)
    return f"{script_name}::{method}"


@pytest.mark.parametrize("test_case", get_test_cases(), ids=get_test_name)
def test_echo(test_case):
    script, method = test_case
    if method == "stdin":
        assert script.run_from_stdin() == script.run_from_stdin(use_ref=True)
    elif method == "string":
        assert script.run_from_str() == script.run_from_str(use_ref=True)
    else:
        assert script.run_from_stdin() == script.run_from_file(use_ref=True)
