import React from 'react'
import SideBar from './SideBar'
import { useState } from 'react'

type Props = {}

export default function GuestLayout({ }: Props) {
    const [open, setOpen] = useState(true);
    const [dropDownOpen, setDropDownOpen] = useState(false);
    return (
        <>
            <SideBar
                open={open}
                setOpen={() => setOpen((cur) => !cur)}
                dropDownOpen={dropDownOpen}
                setDropDownOpen={() => setDropDownOpen((cur) => !cur)}
            />
        </>
    )
}