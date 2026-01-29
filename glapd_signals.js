addToLibrary({
    notify_about_to_check_candidate_primer_region: function(current, total) {
        postMessage({
            'cmd': 'notify_about_to_check_candidate_primer_region',
            current, total
        });
    },
    notify_about_to_check_primer_set_candidate: function(numTargets, current, total) {
        postMessage({
            'cmd': 'notify_about_to_check_primer_set_candidate',
            'numTargets': numTargets,
            'current': current,
            'total': total,
        });
    },
    notify_found_primer_set_candidate_begin: function(f3, f2, f1c, b1c, b2, b3, lf, lb) {
        postMessage({
            'cmd': 'notify_found_primer_set_candidate_begin',
            'args': {
                'f3': UTF8ToString(f3),
                'f2': UTF8ToString(f2),
                'f1c': UTF8ToString(f1c),
                'b1c': UTF8ToString(b1c),
                'b2': UTF8ToString(b2),
                'b3': UTF8ToString(b3),
                'lf': UTF8ToString(lf),
                'lb': UTF8ToString(lb),
            },
        });
    },
    notify_primer_set_candidate_can_be_used_for: function(name) {
        postMessage({
            'cmd': 'notify_primer_set_candidate_can_be_used_for',
            'args': {
                'name': UTF8ToString(name),
            }
        })
    },
    notify_found_primer_set_candidate_end: function() {
        postMessage({
            'cmd': 'notify_found_primer_set_candidate_end',
            'args': {},
        });
    },
});