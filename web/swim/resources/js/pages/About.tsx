import React from 'react'
import HistoryComponent from '../components/HistoryComponent';
import ServicesComponent from '../components/ServicesComponent';
import AwardsComponent from '../components/AwardsComponent';
import ReviewsComponent from '../components/ReviewsComponent';

type Props = {}

export default function About({ }: Props) {

  return (
    <>

      <div className='bg-gradient-b from-slate-400 to-emerald-200'>
        <HistoryComponent />

        <ServicesComponent />

        <AwardsComponent />
      </div>


      <ReviewsComponent />

    </>
  )
}