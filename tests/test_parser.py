from os.path import basename
import pytest

from utils import get_shell_scripts


@pytest.mark.parametrize("script", get_shell_scripts("./parser"), ids=lambda script: basename(script.path))
def test_parser(script):
    assert script.pretty_print_run() == script.pretty_print_run(use_ref=True)

