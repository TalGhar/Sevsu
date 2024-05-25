import React, { useState } from 'react'

import axios from 'axios'

export default function AdminComponent() {

    function getTest() {
        axios.get('http://localhost:8080/admin')
            .then((response) => onSuccess(response))
            .catch((response) => onError(response))
            .finally(() => console.log('Done'))
    }

    function onSuccess(response) {
        console.log(response);

    }

    function onError(response) {
        console.log(response);
    }

    return (
        <div>
            <div className='bg-cyan-300'>
                AdminComponent
                {getTest()}
            </div>
        </div>

    )
}
