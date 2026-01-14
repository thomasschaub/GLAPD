addToLibrary({
    notify_about_to_check_candidate_primer_region: function(current, total) {
        postMessage({
            'cmd': 'notify_about_to_check_candidate_primer_region',
            'current': current,
            'total': total,
        });
    },
    notify_about_to_check_primer_set_candidate: function(numTargets, current, total) {
        postMessage({
            'cmd': 'notify_about_to_check_primer_set_candidate',
            'numTargets': numTargets,
            'current': current,
            'total': total,
        });
    }
});