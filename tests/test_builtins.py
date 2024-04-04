import os.path
import pytest

from utils import get_shell_scripts, ShellScript


def get_test_id(script: ShellScript):
    return os.path.basename(script.path)


@pytest.mark.parametrize("script", get_shell_scripts("builtins/echo"), ids=get_test_id)
def tests_echo(script):
    assert script.run_from_stdin() == script.run_from_stdin(use_ref=True)
